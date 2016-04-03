#include"Data.h"
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#define REP(i,n) for(int i = 0;i<(int)(n);i++)
#define FOREACH(it,container) for(auto it = (container).begin();it != (container).end();it++)

std::string suken::CData::Normalize(std::string Str){		
	for(auto found =  Str.find( "\n" ) ;
			found != std::string::npos ;
			found = Str.find( "\n", found + 1 )){
		Str.replace( found, 1, " " );			
	}
	return Str;
}
bool suken::CData::ReadAll(){	
	struct stat s;
	if(stat(fileName.c_str(),&s)) return WriteAll();		
	std::ifstream ifs(fileName);		
	if(ifs.fail()) return false;		
	while(!ifs.eof()){
		std::string key,val;
		std::getline(ifs,key);
		if(ifs.eof())return true;
		std::getline(ifs,val);
		if(key.size() == 0) continue;
		if(val.size() == 0) continue;
		if(key.c_str()[0] == '#'){
			if(val.c_str()[0] == '#'){
				Set(key.substr(1,key.size()-1),val.substr(1,val.size()-1));				
			}else{
				Set(key.substr(1,key.size()-1),std::atoi(val.c_str()));								
			}
		}else{
			if(val.c_str()[0] == '#'){
				Set(std::atoi(key.c_str()),val.substr(1,val.size()-1));				
			}else{
				Set(std::atoi(key.c_str()),std::atoi(val.c_str()));
			}			
		}
	}		 
	return true;
}

bool suken::CData::WriteAll(){
	std::ofstream ofs(fileName);
	if(ofs.fail()) return false;
	REP(i,vectorIntData.size()){
		ofs << i << "\n" 
			<< vectorIntData[i]<< "\n"; 
	}
	REP(i,vectorStringData.size()){
		ofs << i <<  "\n#" 
			<< Normalize(vectorStringData[i])<< "\n"; 
	}
	FOREACH(it,hashIntData){
		ofs << "#" << Normalize(it->first) 
			<< "\n" << it->second <<"\n"; 
	}
	FOREACH(it,hashStringData){
		ofs << "#" << Normalize(it->first) 
			<< "\n#" << Normalize(it->second) << "\n"; 
	}
	return true;
}
/*
	// HOW_TO_USE SAMPLE
	CData d("teta.txt");
	d.ReadAll();
	d.Set(4,2);
	int a0 = d.GetInt(4);
	d.Set(5,"test\ntest:\"teaf");
	std::string a1 = d.GetString(5);
	d.Set("test\ntest:\"teaf",2);
	int a2 = d.GetInt("test\ntest:\"teaf");
	d.Set("test\ntest:\"teaf","test\ntest:\"teaf");
	std::string a3 = d.GetString("test\ntest:\"teaf");
	d.WriteAll();
*/