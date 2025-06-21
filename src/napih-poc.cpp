#include "napih-poc.hpp"

Napi::Object GreeterWrapper::Init(Napi::Env env, Napi::Object exports) {
  Napi::Function func = GreeterWrapper::DefineClass(
      env,
      "Greeter",
      {
          GreeterWrapper::InstanceMethod("greet", &GreeterWrapper::greet),
      }
  );

  Napi::FunctionReference *ctor = new Napi::FunctionReference();
  *ctor = Napi::Persistent(func);
  exports.Set("Greeter", func);
  return exports;
}

GreeterWrapper::GreeterWrapper(const Napi::CallbackInfo &info)
    : Napi::ObjectWrap<GreeterWrapper>(info) {
  Napi::Env env = info.Env();
  Napi::Value maybeThingToGreet = info[0];

  if (!maybeThingToGreet.IsString()) {
    Napi::TypeError::New(env, "Expected string").ThrowAsJavaScriptException();
    return;
  }

  Napi::String thingToGreet = maybeThingToGreet.As<Napi::String>();
  GreeterInstance = std::make_unique<Greeter>(thingToGreet);
}

Napi::Value GreeterWrapper::greet(const Napi::CallbackInfo &info) {
  return Napi::String::New(info.Env(), GreeterInstance->greet());
}