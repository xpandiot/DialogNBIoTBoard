
void createSendEvent(){
  delay(10000);  // Event trigger time gap
  Serial.println(F("Reading battery..."));
  float battLevel = ideaBoard.getBattPercent(); // Get voltage in percentage
  //float battLevel = 10; // Get voltage in percentage
  delay(1000);

  char json[100] = {0};
  //char* json ="{\"eventName\":\"dataPush\",\"status\":\"none\",\"bat\":10,\"mac\":\"xpandnbiotv26569395562831978\"}";
  //String jsonMessage =  "{\"eventName\":\"dataPush\",\"status\":\"none\",\"bat\":"+String(battLevel,6)+",\"mac\":\""+DEVICE_MAC_ADDRESS+"\"}";
  //String jsonMessage =  "{\"eventName\":\"dataPush\",\"status\":\"none\",\"bat\":"+String(battLevel,6)+",\"mac\":\"123\"}";
  //String jsonMessage = "test";
    String jsonMessage =  "{\"eventName\":\"dataPush\",\"status\":\"none\",\"bat\":"+ String(battLevel) +",\"mac\":\"xpandnbiotv26569395562831978\"}";
 
   
  jsonMessage.toCharArray(json,jsonMessage.length()+1);

   Serial.print(F("Publishing to topic :"));
   Serial.println(EVENT_TOPIC);
   Serial.println(F("Message : "));
   Serial.println(jsonMessage);

  
  if (! sensor.publish(json)) {
      Serial.println(F("Failed"));
      txfailures++;
    } else {
      Serial.println(F("OK!"));
      txfailures = 0;
    }
}

void do_actions(const char* message) {
  //Create this function according to your actions. you will receive a message something like this   
StaticJsonBuffer<200> jsonBuffer;
JsonObject& root = jsonBuffer.parseObject(message);

String mac = root["mac"]; // "power"
String action = root["action"]; // "1902100379354041"

  if(mac.equals(DEVICE_MAC_ADDRESS)){
    if(action == "ON"){
      Serial.println("Turning ON");
      // type your code to turn on
    }
    else if(action == "OFF"){
      Serial.println("Turning OFF");    
      // type your code to turn off
    }
  }
}
