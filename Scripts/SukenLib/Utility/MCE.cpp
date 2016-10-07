#include"MCE.h"
#include"Debug.h"

const std::string sWidth = "width";
const std::string sHeight = "height";

suken::CMCEData::~CMCEData(){
	delete[] chip;
}

void suken::CMCEData::Awake(const char* _file){
	file = _file;
	data = new CData(file.c_str());
	data->ReadAll();
	width = data->GetInt(sWidth);
	height = data->GetInt(sHeight);
	chip = new int (3*width*height);
	for(int i = 0; i < 3*width*height;i++){
		chip[i] = data->GetInt(i);
	}
	delete data;
}

int suken::CMCEData::GetChip(char layer,int x,int y){
	return chip[Array(layer,x,y)];
}

int suken::CMCEData::Array(char layer,int x,int y){
#ifdef DEBUG
	if(layer >= 3 || x >= width || y >= height){
		WarningSK("MCE-警告：数値が大きすぎます。強制終了します");
		exit(1);
		
	}else{
		return layer * width * height + x * height + y;
	}
#else
	return layer * width * height + x * height + y;
#endif
}

suken::CMCE::CMCE():
layerA(0),layerB(1),layerC(2){

}


void suken::CMCE::Read(const char* _file){
	std::string str = folder;
	str += _file;
	FILE* a = fopen(str.c_str(),"r");
	if(a != nullptr){
		fclose(a);
		file.Awake(str.c_str());
	}
}

int suken::CMCE::Get(char layer,int x,int y){
	return file.GetChip(layer,x,y);
}

suken::CMCE mce;