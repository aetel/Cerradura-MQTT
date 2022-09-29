
#include "cliente_mqtt.h"

  void(* resetFunc) (void) = 0;

  /* Funcion para iniciar el servidor MQTT, se establecen direcciones y puerto y funcion de callback que procesara los mensajes entrantes */
  
  void arrancar_cliente_mqtt(){
    
    client.setServer(mqtt_server,1883);
    client.setCallback(callback);
  
    
  } //end arrancar_cliente_mqtt()




  /* La funcion manejadorClienteMQTT se encarga de mantener la conexion con el broker MQTT activa y actuar de forma adecuada en caso de perderse */
  
  void manejadorClienteMQTT(){
      
    
    if (!client.connected()) {
      
      Serial.println(client.state());
      reconnect();
      
    } // end if 
    
    client.loop();
    delay(1); // Needed to add a delay of 1ms otherwise the connection drops with -4 error. After adding this the connection is stable
    
  } //end MANEJADOR_SERVIDOR_MQTT





  /* La funcion que encontramos a continuacion se encarga de procesar los mensajes que le llegan al ESP8266 del BROKER (Raspberry Pi), analizarlos y actuar en consecuencia,
     llamando a las funciones correspondientes para el manejo del hardware del sistema */
  
  void callback(char* topic, byte* payload, unsigned int length) { // Esta funcion se ejecuta con la llegada de mensajes MQTT, analiza el topic por el que llega 
                                                                  // el mensaje y en funcion de ello se tomaran las decisiones pertinentes
    Serial.print("Message arrived [");
    Serial.print(topic);
    Serial.print("] ");
    String msg;
    String topic_subs(topic);
    
    for (int i = 0; i < length; i++) {
      Serial.print((char)payload[i]);
      msg +=(char)payload[i];
      } //end for 
      
      Serial.println(msg);
      Serial.println("MENSAJE POR AQUI");
      
      if(topic_subs.equals(topic_subs_puerta) && msg == "1"){
        
      Serial.println("ABRASE LA PUERTA !");
      gestionPuerta();
        
      } //end if
      if(topic_subs.equals(topic_log_puerta) && msg == "1"){
        resetFunc(); //call reset  
        }
      
  } // end CALLBACK()
  
  
  
  bool subs_topic (){
    
  bool estado = false;
  
    if(client.subscribe(topic_subs_puerta)&&client.subscribe(topic_log_puerta)&&client.subscribe(topic_LWT_puerta)){
      
      estado = true;
      
    } //end if


        
    return estado;
    
  }// end SUBS_TOPICS()
  
  
  

  /* Esta funcion se encarga de reconectar (o conectar, si es la primera vez que se realiza la operacion) el ESP8266 al BROKER MQTT (Raspberry)
     en resumidas cuentas, establece y mantiene la conexion con el BROKER MQTT */
  
  void reconnect() {
       String clientId = "ESP8266Client_Puerta";
      //clientId += String(random(0xffff), HEX);
      


  
    while (!client.connected()&intentos_conexion < 5) {
      
      Serial.print("Attempting MQTT connection...");
      // Create a random client ID

      // Attempt to connect
      if (client.connect(clientId.c_str(),mqtt_server_user,mqtt_server_password,"cmnd/PUERTA/LWT", 1, true, "offline")) {
        client.publish("cmnd/PUERTA/LWT", "online", true);
        //Si se conecta, pues lo subscribimos al topic que nos mandan
        if(subs_topic ()){
          
          Serial.println("Connected");
          
        
        }else{
          
          Serial.println("Error al subscribirse a los topic");
        
        } // end else
        
      } else {
        
        Serial.print("failed, rc=");
        Serial.print(client.state());
        Serial.println(" try again in 5 seconds");
        intentos_conexion++;
        // Wait 5 seconds before retrying
        delay(5000);
        
      } // end else 
    } // end while
  } // end RECONNECT()
