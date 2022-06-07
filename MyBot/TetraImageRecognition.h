#pragma once
#include "Tetra.h"
class TetraImageRecognition
{
private:
	//TO-DO: Link AWS Libraries
	//Aws::SDKOptions Options;
	//Aws::S3::S3Client ForiS3Client;
	//Aws::S3::Model::Bucket ForiBucket;
	//Aws::Rekognition::Model::Image ScannedImage;
	//Aws::Rekognition::RekognitionClient ForiRekClient;
public:
	bool RecognizeBadWords(std::string Text);
	TetraImageRecognition();
	~TetraImageRecognition();
	//bool PlaceObject(const Aws::String& BucketName, const Aws::String& ObjectName, const Aws::String& region);
	//void UploadModerateDeleteSendConf(const Aws::String& BucketName, const Aws::String& ObjectName, const Aws::String& region);
};

