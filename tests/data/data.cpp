#include <ffw/data.h>
#define CATCH_CONFIG_MAIN
#include "../catch.hpp"

TEST_CASE("Encode Json", "[JSON]"){
	ffw::Var data = ffw::Object({
		{"string", "\"world\""},
		{"integer", 123},
		{"float", 42.42f},
		{"bool", true},
		{"array", ffw::Array({"first", "second", "third"})}
	});

	ffw::Var test = ffw::decodeJson(ffw::encodeJson(data));

	REQUIRE(test.is<ffw::Object>());
	ffw::Object& obj = test.getAs<ffw::Object>();
	REQUIRE(obj.find("string") != obj.end());
	REQUIRE(obj.find("integer") != obj.end());
	REQUIRE(obj.find("float") != obj.end());
	REQUIRE(obj.find("bool") != obj.end());
	REQUIRE(obj.find("array") != obj.end());

	REQUIRE(obj["string"].is<std::string>());
	REQUIRE(obj["integer"].is<int>());
	REQUIRE(obj["float"].is<float>());
	REQUIRE(obj["bool"].is<bool>());
	REQUIRE(obj["array"].is<ffw::Array>());

	REQUIRE("\"world\"" == (std::string)obj["string"]);
	REQUIRE(123 == (int)obj["integer"]);
	REQUIRE(42.42f == (float)obj["float"]);
	REQUIRE(true == obj["bool"].toBool());
	REQUIRE(3 == obj["array"].getAs<ffw::Array>().size());
	REQUIRE("first" == (std::string)obj["array"][0]);
	REQUIRE("second" == (std::string)obj["array"][1]);
	REQUIRE("third" == (std::string)obj["array"][2]);

	//std::string compare = "{\"string\":\"\\\"world\\\"\",\"integer\":123,\"float\":42.419998,\"bool\":true,\"array\":[\"first\",\"second\",\"third\"]}";
    //std::string compare = "{\"string\":\"\\\"world\\\"\",\"bool\":true,\"float\":42.419998,\"integer\":123,\"array\":[\"first\",\"second\",\"third\"]}";
	//TEST_EQUAL(compare, jsonstr);
}

TEST_CASE("Decode Json", "[JSON]"){
	ffw::Var data;

	std::string jsonstr = "{\"string\":\"\\\"world\\\"\",\"integer\":123,\"float\":42.419998,\"bool\":true,\"array\":[\"first\",\"second\",\"third\"]}";
	data = ffw::decodeJson(jsonstr);

	REQUIRE(data.is<ffw::Object>());

	ffw::Object& json = data.getAs<ffw::Object>();

	REQUIRE(json.size() == 5);
	REQUIRE(json.find("string") != json.end());
	REQUIRE(json.find("integer") != json.end());
	REQUIRE(json.find("float") != json.end());
	REQUIRE(json.find("bool") != json.end());
	REQUIRE(json.find("array") != json.end());

	REQUIRE(json["string"].is<std::string>());
	REQUIRE(json["integer"].is<int>());
	REQUIRE(json["float"].is<float>());
	REQUIRE(json["bool"].is<bool>());
	REQUIRE(json["array"].is<ffw::Array>());

	REQUIRE("\"world\"" == (std::string)json["string"]);
	REQUIRE(123 == (int)json["integer"]);
	REQUIRE(42.42f == (float)json["float"]);
	REQUIRE(true == json["bool"].toBool());
	REQUIRE(3 == json["array"].getAs<ffw::Array>().size());
	REQUIRE("first" == (std::string)json["array"][0]);
	REQUIRE("second" == (std::string)json["array"][1]);
	REQUIRE("third" == (std::string)json["array"][2]);
}

TEST_CASE("Decode Json #2", "[JSON]") {
	ffw::Var data;

	std::string jsonstr = 
		"{\n\
			\"string\"  :    \"\\\"world\\\"\"     ,\n\
			\"integer\"    :   123     ,\n\
			\"float\"  :  42.419998       ,\n\
			\"bool\"   :    true    ,\n\
			\"array\"  :   [   \"first\"    ,   \"second\"    ,   \"third\"   ]\n\
		}";
	data = ffw::decodeJson(jsonstr);

	REQUIRE(data.is<ffw::Object>());

	ffw::Object& json = data.getAs<ffw::Object>();

	REQUIRE(json.size() == 5);
	REQUIRE(json.find("string") != json.end());
	REQUIRE(json.find("integer") != json.end());
	REQUIRE(json.find("float") != json.end());
	REQUIRE(json.find("bool") != json.end());
	REQUIRE(json.find("array") != json.end());

	REQUIRE(json["string"].is<std::string>());
	REQUIRE(json["integer"].is<int>());
	REQUIRE(json["float"].is<float>());
	REQUIRE(json["bool"].is<bool>());
	REQUIRE(json["array"].is<ffw::Array>());

	REQUIRE("\"world\"" == (std::string)json["string"]);
	REQUIRE(123 == (int)json["integer"]);
	REQUIRE(42.42f == (float)json["float"]);
	REQUIRE(true == json["bool"].toBool());
	REQUIRE(3 == json["array"].getAs<ffw::Array>().size());
	REQUIRE("first" == (std::string)json["array"][0]);
	REQUIRE("second" == (std::string)json["array"][1]);
	REQUIRE("third" == (std::string)json["array"][2]);
}

TEST_CASE("Decode Json #3", "[JSON]"){
	static const std::string jsonstr = "\
	{\"menu\": {\n\
	  \"id\": \"file\",\n\
	  \"value\": \"File\",\n\
	  \"popup\": {\n\
		\"menuitem\": [\n\
		  {\"value\": \"New\", \"onclick\": \"CreateNewDoc()\"},\n\
		  {\"value\": \"open\", \"onclick\": \"OpenDoc()\"},\n\
		  {\"value\": \"close\", \"onclick\": \"CloseDoc()\"}\n\
		]\n\
	  }\n\
	}}";

	ffw::Var data = ffw::decodeJson(jsonstr);

	REQUIRE(data.is<ffw::Object>());

	ffw::Object& json = (ffw::Object&)data;

	REQUIRE(json.find("menu") != json.end());

	REQUIRE(json["menu"]["id"].is<std::string>());
	REQUIRE(json["menu"]["value"].is<std::string>());
	REQUIRE(json["menu"]["popup"].is<ffw::Object>());

	REQUIRE("file" == (std::string)json["menu"]["id"]);
	REQUIRE("File" == (std::string)json["menu"]["value"]);
	REQUIRE(1 == ((ffw::Object)json["menu"]["popup"]).size());

	REQUIRE(json["menu"]["popup"]["menuitem"].is<ffw::Array>());

	auto& arr = json["menu"]["popup"]["menuitem"].getAs<ffw::Array>();

	REQUIRE(3 == arr.size());

	REQUIRE(arr[0].is<ffw::Object>());
	REQUIRE(arr[1].is<ffw::Object>());
	REQUIRE(arr[2].is<ffw::Object>());

	auto& obj0 = (ffw::Object&)arr[0];
	REQUIRE(obj0.find("value") != obj0.end());
	REQUIRE(obj0.find("onclick") != obj0.end());

	auto& obj1 = (ffw::Object&)arr[1];
	REQUIRE(obj1.find("value") != obj1.end());
	REQUIRE(obj1.find("onclick") != obj1.end());

	auto& obj2 = (ffw::Object&)arr[2];
	REQUIRE(obj2.find("value") != obj2.end());
	REQUIRE(obj2.find("onclick") != obj2.end());

	REQUIRE("New" == (std::string)obj0["value"]);
	REQUIRE("CreateNewDoc()" == (std::string)obj0["onclick"]);

	REQUIRE("open" == (std::string)obj1["value"]);
	REQUIRE("OpenDoc()" == (std::string)obj1["onclick"]);

	REQUIRE("close" == (std::string)obj2["value"]);
	REQUIRE("CloseDoc()" == (std::string)obj2["onclick"]);
}

TEST_CASE("Decode Json #4", "[JSON]") {
	static const std::string jsonstr = "\
	{\n\
		\"object\": {\n\
		},\n\
		\"array\": [\n\
		]\n\
	}";

	ffw::Var data = ffw::decodeJson(jsonstr);

	REQUIRE(data.is<ffw::Object>());

	ffw::Object& json = (ffw::Object&)data;

	REQUIRE(json.contains("object"));
	REQUIRE(json.contains("array"));

	REQUIRE(json["object"].is<ffw::Object>());
	REQUIRE(json["array"].is<ffw::Array>());

	REQUIRE(json["object"].getAs<ffw::Object>().size() == 0);
	REQUIRE(json["array"].getAs<ffw::Array>().size() == 0);
}

TEST_CASE("Encode XML", "[XML]"){
	ffw::Var data = ffw::Object({
		{"string", "\"world\""},
		{"integer", 123},
		{"float", 42.42f},
		{"bool", true},
		{"array", ffw::Array({"first", "second", "third"})}
	});

	//std::string xmlstr = ffw::encodeXml(data);

	//std::string compare = "<?xml version=\"1.0\" encoding=\"UTF-8\"?><document><string>&quot;world&quot;</string><integer>123</integer><float>42.419998</float><bool>true</bool><array>first</array><array>second</array><array>third</array></document>";

	//TEST_EQUAL(compare, xmlstr);

	ffw::Var test = ffw::decodeXml(ffw::encodeXml(data));

	REQUIRE(test.is<ffw::Object>());
	ffw::Object& obj = test.getAs<ffw::Object>()["document"].getAs<ffw::Object>();
	REQUIRE(obj.find("string") != obj.end());
	REQUIRE(obj.find("integer") != obj.end());
	REQUIRE(obj.find("float") != obj.end());
	REQUIRE(obj.find("bool") != obj.end());
	REQUIRE(obj.find("array") != obj.end());

	REQUIRE(obj["string"].is<std::string>());
	REQUIRE(obj["integer"].is<int>());
	REQUIRE(obj["float"].is<float>());
	REQUIRE(obj["bool"].is<bool>());
	REQUIRE(obj["array"].is<ffw::Array>());
}

TEST_CASE("Decode XML", "[XML]"){
	ffw::Var data;

	std::string xmlstr = "<?xml version=\"1.0\" encoding=\"UTF-8\"?><document><string>&quot;world&quot;</string><integer>123</integer><float>42.419998</float><bool>true</bool><array>first</array><array>second</array><array>third</array></document>";
	data = ffw::decodeXml(xmlstr);

	REQUIRE(data.is<ffw::Object>());

	REQUIRE(data.getAs<ffw::Object>().size() == 1);
	REQUIRE(data.getAs<ffw::Object>().begin()->first == "document");
	REQUIRE(data.getAs<ffw::Object>().begin()->second.is<ffw::Object>());

	ffw::Object& xml = (ffw::Object&)data["document"];

	REQUIRE(xml.size() == 5);
	REQUIRE(xml.find("string") != xml.end());
	REQUIRE(xml.find("integer") != xml.end());
	REQUIRE(xml.find("float") != xml.end());
	REQUIRE(xml.find("bool") != xml.end());
	REQUIRE(xml.find("array") != xml.end());

	REQUIRE(xml["string"].is<std::string>());
	REQUIRE(xml["integer"].is<int>());
	REQUIRE(xml["float"].is<float>());
	REQUIRE(xml["bool"].is<bool>());
	REQUIRE(xml["array"].is<ffw::Array>());

	REQUIRE("\"world\"" == (std::string)xml["string"]);
	REQUIRE(123 == (int)xml["integer"]);
	REQUIRE(42.42f == (float)xml["float"]);
	REQUIRE(true == xml["bool"].toBool());
	REQUIRE(3 == xml["array"].getAs<ffw::Array>().size());
	REQUIRE("first" == (std::string)xml["array"][0]);
	REQUIRE("second" == (std::string)xml["array"][1]);
	REQUIRE("third" == (std::string)xml["array"][2]);
}

static const std::string csvtest[12] = {
"street,city,zip,state,beds,baths,sq__ft,type,sale_date,price,latitude,longitude",
"3526 HIGH ST,SACRAMENTO,95838,CA,2,1,836,Residential,Wed May 21 00:00:00 EDT 2008,59222,38.631913,-121.434879",
"51 OMAHA CT,SACRAMENTO,95823,CA,3,1,1167,Residential,Wed May 21 00:00:00 EDT 2008,68212,38.478902,-121.431028",
"2796 BRANCH ST,SACRAMENTO,95815,CA,2,1,796,Residential,Wed May 21 00:00:00 EDT 2008,68880,38.618305,-121.443839",
"2805 JANETTE WAY,SACRAMENTO,95815,CA,2,1,852,Residential,Wed May 21 00:00:00 EDT 2008,69307,38.616835,-121.439146",
"6001 MCMAHON DR,SACRAMENTO,95824,CA,2,1,797,Residential,Wed May 21 00:00:00 EDT 2008,81900,38.51947,-121.435768",
"5828 PEPPERMILL CT,SACRAMENTO,95841,CA,3,1,1122,Condo,Wed May 21 00:00:00 EDT 2008,89921,38.662595,-121.327813",
"6048 OGDEN NASH WAY,SACRAMENTO,95842,CA,3,2,1104,Residential,Wed May 21 00:00:00 EDT 2008,90895,38.681659,-121.351705",
"2561 19TH AVE,SACRAMENTO,95820,CA,3,1,1177,Residential,Wed May 21 00:00:00 EDT 2008,91002,38.535092,-121.481367",
"11150 TRINITY RIVER DR Unit 114,RANCHO CORDOVA,95670,CA,2,2,941,Condo,Wed May 21 00:00:00 EDT 2008,94905,38.621188,-121.270555",
"7325 10TH ST,RIO LINDA,95673,CA,3,2,1146,Residential,Wed May 21 00:00:00 EDT 2008,98937,38.700909,-121.442979",
"645 MORRISON AVE,SACRAMENTO,95838,CA,3,2,909,Residential,Wed May 21 00:00:00 EDT 2008,100309,38.637663,-121.45152"
};

static const std::string csvfile =
"street,city,zip,state,beds,baths,sq__ft,type,sale_date,price,latitude,longitude\n\
3526 HIGH ST,SACRAMENTO,95838,CA,2,1,836,Residential,Wed May 21 00:00:00 EDT 2008,59222,38.631913,-121.434879\n\
\n\
51 OMAHA CT,SACRAMENTO,95823,CA,3,1,1167,Residential,Wed May 21 00:00:00 EDT 2008,68212,38.478902,-121.431028\n\
                \n\
\n\
2796 BRANCH ST,SACRAMENTO,95815,CA,2,1,796,Residential,Wed May 21 00:00:00 EDT 2008,68880,38.618305,-121.443839\n\
2805 JANETTE WAY,SACRAMENTO,95815,CA,2,1,852,Residential,Wed May 21 00:00:00 EDT 2008,69307,38.616835,-121.439146\n\
6001 MCMAHON DR,SACRAMENTO,95824,CA,2,1,797,Residential,Wed May 21 00:00:00 EDT 2008,81900,38.51947,-121.435768\n\
5828 PEPPERMILL CT,SACRAMENTO,95841,CA,3,1,1122,Condo,Wed May 21 00:00:00 EDT 2008,89921,38.662595,-121.327813\n\
6048 OGDEN NASH WAY,SACRAMENTO,95842,CA,3,2,1104,Residential,Wed May 21 00:00:00 EDT 2008,90895,38.681659,-121.351705\n\
2561 19TH AVE,SACRAMENTO,95820,CA,3,1,1177,Residential,Wed May 21 00:00:00 EDT 2008,91002,38.535092,-121.481367\n\
11150 TRINITY RIVER DR Unit 114,RANCHO CORDOVA,95670,CA,2,2,941,Condo,Wed May 21 00:00:00 EDT 2008,94905,38.621188,-121.270555\n\
7325 10TH ST,RIO LINDA,95673,CA,3,2,1146,Residential,Wed May 21 00:00:00 EDT 2008,98937,38.700909,-121.442979\n\
645 MORRISON AVE,SACRAMENTO,95838,CA,3,2,909,Residential,Wed May 21 00:00:00 EDT 2008,100309,38.637663,-121.45152";

TEST_CASE("open CSV File", "[CSV]"){
	ffw::CsvLoader csv;

	csv.openFromFile("sample.csv");

	size_t i = 0;
	while(!csv.eof()){
		REQUIRE(i < 12);
		REQUIRE(csvtest[i] == csv.getRowRaw());
		i++;
	}
}

TEST_CASE("open CSV Data", "[CSV]"){
	ffw::CsvLoader csv;

	csv.openFromData(csvfile);

	size_t i = 0;
	while(!csv.eof()){
		REQUIRE(i < 12);
		REQUIRE(csvtest[i] == csv.getRowRaw());
		i++;
	}
}

TEST_CASE("CSV Tokenizer", "[CSV]"){
	static const std::string str0 = "1997,Ford,E350";
	ffw::Array arr0 = ffw::CsvLoader::tokenize(str0, 0, str0.size(), true, ',', '\"');

	REQUIRE(arr0[0].is<int>());
	REQUIRE(arr0[1].is<std::string>());
	REQUIRE(arr0[2].is<std::string>());

	REQUIRE(1997 == (int)arr0[0]);
	REQUIRE("Ford" == (std::string&)arr0[1]);
	REQUIRE("E350" == (std::string&)arr0[2]);

	static const std::string str1 = "\"1997\",\"Ford\",\"E350\"";
	ffw::Array arr1 = ffw::CsvLoader::tokenize(str1, 0, str1.size(), true, ',', '\"');

	REQUIRE(arr1[0].is<int>());
	REQUIRE(arr1[1].is<std::string>());
	REQUIRE(arr1[2].is<std::string>());

	REQUIRE(1997 == (int)arr1[0]);
	REQUIRE("Ford" == (std::string&)arr1[1]);
	REQUIRE("E350" == (std::string&)arr1[2]);

	// leading and trailing spaces trimming is forbidden by RFC 4180
	static const std::string str2 = "1997, Ford, E350";
	ffw::Array arr2 = ffw::CsvLoader::tokenize(str2, 0, str2.size(), true, ',', '\"');

	REQUIRE(arr2[0].is<int>());
	REQUIRE(arr2[1].is<std::string>());
	REQUIRE(arr2[2].is<std::string>());

	REQUIRE(1997 == (int)arr2[0]);
	REQUIRE(" Ford" == (std::string&)arr2[1]);
	REQUIRE(" E350" == (std::string&)arr2[2]);

	static const std::string str3 = "1997, \"Ford\" ,E350";
	ffw::Array arr3 = ffw::CsvLoader::tokenize(str3, 0, str3.size(), true, ',', '\"');

	REQUIRE(arr3[0].is<int>());
	REQUIRE(arr3[1].is<std::string>());
	REQUIRE(arr3[2].is<std::string>());

	REQUIRE(1997 == (int)arr3[0]);
	REQUIRE("Ford" == (std::string&)arr3[1]);
	REQUIRE("E350" == (std::string&)arr3[2]);

	static const std::string str4 = "1997,Ford,E350,\" Super luxurious truck \"";
	ffw::Array arr4 = ffw::CsvLoader::tokenize(str4, 0, str4.size(), true, ',', '\"');

	REQUIRE(arr4[0].is<int>());
	REQUIRE(arr4[1].is<std::string>());
	REQUIRE(arr4[2].is<std::string>());

	REQUIRE(1997 == (int)arr4[0]);
	REQUIRE("Ford" == (std::string&)arr4[1]);
	REQUIRE("E350" == (std::string&)arr4[2]);
	REQUIRE(" Super luxurious truck " == (std::string&)arr4[3]);

	static const std::string str5 = "";
	ffw::Array arr5 = ffw::CsvLoader::tokenize(str5, 0, str5.size(), true, ',', '\"');
	REQUIRE(1 == arr5.size());
	REQUIRE(arr5[0].empty());

	static const std::string str6 = ",,";
	ffw::Array arr6 = ffw::CsvLoader::tokenize(str6, 0, str6.size(), true, ',', '\"');
	REQUIRE(3 == arr6.size());
	REQUIRE(arr6[0].empty());
	REQUIRE(arr6[1].empty());
	REQUIRE(arr6[2].empty());

	static const std::string str7 = "\"\",\"\",\"\"";
	ffw::Array arr7 = ffw::CsvLoader::tokenize(str7, 0, str7.size(), true, ',', '\"');
	REQUIRE(3 == arr7.size());
	REQUIRE(arr7[0].is<std::string>());
	REQUIRE(arr7[1].is<std::string>());
	REQUIRE(arr7[2].is<std::string>());

	static const std::string str8 = "true,false,\"true\",\"false\"";
	ffw::Array arr8 = ffw::CsvLoader::tokenize(str8, 0, str8.size(), true, ',', '\"');
	REQUIRE(4 == arr8.size());
	REQUIRE(arr8[0].is<bool>());
	REQUIRE(arr8[1].is<bool>());
	REQUIRE(arr8[2].is<bool>());
	REQUIRE(arr8[3].is<bool>());

	REQUIRE(arr8[0].toBool());
	REQUIRE_FALSE(arr8[1].toBool());
	REQUIRE(arr8[2].toBool());
	REQUIRE_FALSE(arr8[3].toBool());

	static const std::string str9 = "1999,Chevy,\"Venture \"\"Extended Edition, Very Large\"\"\",,5000.00";
	ffw::Array arr9 = ffw::CsvLoader::tokenize(str9, 0, str9.size(), true, ',', '\"');

	REQUIRE(5 == arr9.size());

	REQUIRE(arr9[0].is<int>());
	REQUIRE(arr9[1].is<std::string>());
	REQUIRE(arr9[2].is<std::string>());
	REQUIRE(arr9[3].empty());
	REQUIRE(arr9[4].is<float>());

	REQUIRE(1999 == (int)arr9[0]);
	REQUIRE("Chevy" == (std::string&)arr9[1]);
	REQUIRE("Venture \"Extended Edition, Very Large\"" == (std::string&)arr9[2]);
	REQUIRE(5000.00 == (float)arr9[4]);
}

TEST_CASE("CSV Decode", "[CSV]"){
	static const std::string str =
	"Year,Make,Model,length\n\
	1997,Ford,E350,2.34\n\
	2000,Mercury,Cougar,2.38";

	ffw::Array arr = ffw::decodeCsv(str);

	REQUIRE(3 == arr.size());

	REQUIRE(arr[0].is<ffw::Array>());
	REQUIRE(arr[1].is<ffw::Array>());
	REQUIRE(arr[2].is<ffw::Array>());

	REQUIRE(4 == arr[0].getAs<ffw::Array>().size());
	REQUIRE(4 == arr[1].getAs<ffw::Array>().size());
	REQUIRE(4 == arr[2].getAs<ffw::Array>().size());
}
