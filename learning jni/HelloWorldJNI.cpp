#include "HelloWorldJNI.h"
#include <iostream>
#include "json.hpp"
#include "fstream"

using json = nlohmann::json;

/*
 * Class:     com_baeldung_jni_HelloWorldJNI
 * Method:    sayHello
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_HelloWorldJNI_sayHello (JNIEnv* env, jobject thisObject) {
	std::fstream file("wtf.txt");
    json j2 = {
  {"pi", 3.141},
  {"happy", true},
  {"name", "Niels"},
  {"nothing", nullptr},
  {"answer", {
    {"everything", 42}
  }},
  {"list", {1, 0, 2}},
  {"object", {
    {"currency", "USD"},
    {"value", 42.99}
  }}
};
    std::string hello = j2.dump();
    std::cout << hello << std::endl;
    return env->NewStringUTF(hello.c_str());
}