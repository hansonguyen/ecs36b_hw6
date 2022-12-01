
// ecs36b first program

#include <iostream>
#include "ecs36b_Exception.h"
#include <cstring>

// JSON RPC part
#include "hw6client.h"
#include <jsonrpccpp/client/connectors/httpclient.h>

using namespace jsonrpc;
using namespace std;

int
main()
{
  // distributed wordle demo for 11/23/2022
  // HttpClient httpclient("http://127.0.0.1:8384");
  HttpClient httpclient("https://2ada-73-66-168-157.ngrok.io");
  hw6Client myClient(httpclient, JSONRPC_CLIENT_V2);
  Json::Value myv;
  Json::Value jv_list;
  
  jv_list[0] = "919227725";
  jv_list[1] = "918470625";
  jv_list[2] = "917137244";
  jv_list[3] = "919388431";
  
  //
  try {
    myv = myClient.set_name("set_name", jv_list, "Team please give us an A");
  } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  std::cout << myv.toStyledString() << std::endl;

  try {
    // worry
    myv = myClient.guess("guess", "Wordle", "19056_2022-11-24T20:26:16+0000",
			 "worry");
  } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  std::cout << myv.toStyledString() << std::endl;

  try {
    // worry
    myv = myClient.submit("submit", "19056_2022-11-24T20:26:16+0000", "foo");
  } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  std::cout << myv.toStyledString() << std::endl;

  // obtain and new
  try {
    myv = myClient.obtain("obtain", "Wordle", "00000000");
  } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
  }
  std::cout << myv.toStyledString() << std::endl;

  // guess
  if ((myv["game_id"].isNull() == false) &&
      (myv["game_id"].isString() == true))
    {
      try {
	// earth
	myv = myClient.guess("guess", "Wordle", myv["game_id"].asString(),
			     "earth");
      } catch (JsonRpcException &e) {
	cerr << e.what() << endl;
      }

      // exit(-1);

      try {
	// mound
	myv = myClient.guess("guess", "Wordle", myv["game_id"].asString(),
			     "mound");
      } catch (JsonRpcException &e) {
	cerr << e.what() << endl;
      }

      try {
	// sicky
	myv = myClient.guess("guess", "Wordle", myv["game_id"].asString(),
			     "sicky");
      } catch (JsonRpcException &e) {
	cerr << e.what() << endl;
      }

      std::cout << myv.toStyledString() << std::endl;
    }

  // New Code

  return 0;
}
