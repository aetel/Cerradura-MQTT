#include "gestionWifi.h"


  /* Esta funcion se encarga del establecimiento de la conexion WiFi, ademas se establecen una serie de parametros, que entre otras cosas
     definen la direccion IP del ESP8266 y la direccion del router. */
  
  void setup_wifi() {
  
    estadoConexion = NCONECTADO; // Variable muy importante para que la gestion de la conexion WiFi, tenga estado, y se pueda actuar en funcion del mismo (VER SWICH CASE)
  
    delay(10);
    
    // Nos conectamos a la red WiFi
    IPAddress ip(10,0,60,200);     
    IPAddress gateway(10,0,60,1);   
    IPAddress subnet(255,255,255,0);  
     
    Serial.println();
    Serial.print("Conectando a  ");
    Serial.println(ssid);
    
    WiFi.mode(WIFI_STA);
    WiFi.config(ip, gateway, subnet);
    WiFi.begin(ssid, password);
    
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
    estadoConexion = CONECTADO;
    
    randomSeed(micros());
    
    Serial.println("");
    Serial.println("WiFi conectado");
    Serial.print("Direccion IP : ");
    Serial.println(WiFi.localIP());
  } // end SETUP_WIFI()
  
  


  /* La funcion que encontramos a continuacion, se encarga de mantener la conexion del wifi, esto es, si por alguna razon la conexion WiFi ss cae o se pierde 
     el ESP8266 tiene la capacidad de recuperala, esto lo hace, cambiando de estado al estado NCONECTADO, donde pasara de nuevo al estado inicial de busqueda de 
     redes WiFi conocidas */
     
  void estadoWifi(){
  
    switch(estadoConexion){
    
      case CONECTADO:
      
        if(WiFi.status() != WL_CONNECTED){
          estadoConexion = NCONECTADO;
          Serial.println("ESTADO WIFI: CONEXION PERDIDA");
        } //end if 
        
      break;
      
      default: // NCONECTADO por defecto 
      
        while (WiFi.status() != WL_CONNECTED) {
          delay(500);
          Serial.print(".");
        }
        estadoConexion = CONECTADO;
        Serial.println("");
        Serial.println("ESTADO WIFI: RECONECTADO");
        Serial.print("Direccion IP : ");
        Serial.println(WiFi.localIP());
        
      break;
      
    } //end SWITCH
  } //end ESTADO_WIFI()
