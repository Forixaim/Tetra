#pragma once
#include "Tetra.h"
class TetraImageRecognition
{
private:
	dpp::attachment ImageRecognition;
	Aws::SDKOptions Options;
	Aws::S3::Model::Bucket ForiBucket;
public:
	TetraImageRecognition();
	~TetraImageRecognition();
};

