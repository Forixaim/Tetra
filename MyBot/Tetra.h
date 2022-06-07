#pragma once
//Libraries
#include <dpp/dpp.h>
#include <aws/core/Aws.h>
#include <aws/core/utils/Outcome.h>
#include <aws/core/config/AWSProfileConfigLoader.h>
#include <aws/rekognition/RekognitionClient.h>
#include <aws/rekognition/model/ListCollectionsRequest.h>
#include <aws/rekognition/model/ListCollectionsResult.h>
#include <aws/rekognition/model/CreateCollectionRequest.h>
#include <aws/rekognition/model/IndexFacesRequest.h>
#include <aws/rekognition/model/Image.h>
#include <aws/rekognition/model/SearchFacesByImageRequest.h>
#include <aws/rekognition/model/ListFacesRequest.h>
#include <aws/rekognition/model/ListFacesResult.h>
#include <aws/core/platform/Environment.h>
#include <aws/s3/model/Bucket.h>
#include <aws/s3/model/Object.h>
#include <aws/s3/S3Client.h>
#include <aws/s3/S3Request.h>
//Modules

//Other Headers
#include "BotInfo.h"
#include "EssentialTemplates.h"