#include <napi.h>

#include "./sub/sub.h"
#include "./add/add.h"

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "add"), Napi::Function::New(env, Add));
  exports.Set(Napi::String::New(env, "sub"), Napi::Function::New(env, Sub));

  return exports;
}

NODE_API_MODULE(addon, Init)