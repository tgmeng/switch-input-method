#include <napi.h>
#include "./switch_input_method.h"

Napi::Boolean SwitchEnglishInputMethod(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  return Napi::Boolean::New(env, switchEnglishInputMethod());
}

Napi::Boolean RestorePreviousInputMethods(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  return Napi::Boolean::New(env, restorePreviousInputMethods());
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "switchEnglishInputMethod"),
              Napi::Function::New(env, SwitchEnglishInputMethod));
  exports.Set(Napi::String::New(env, "restorePreviousInputMethods"),
              Napi::Function::New(env, RestorePreviousInputMethods));
  return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)