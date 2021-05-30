#include <napi.h>
#include "./switch_input_method.h"

Napi::Boolean SwitchEnglishInputMethod(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  return Napi::Boolean::New(env, switchEnglishInputMethod());
}

Napi::Boolean RestorePreviousInputMethod(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  return Napi::Boolean::New(env, restorePreviousInputMethod());
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "switchEnglishInputMethod"),
              Napi::Function::New(env, SwitchEnglishInputMethod));
  exports.Set(Napi::String::New(env, "restorePreviousInputMethod"),
              Napi::Function::New(env, RestorePreviousInputMethod));
  return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)