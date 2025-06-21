#include "Greeter.hpp"
#include <napi.h>

class GreeterWrapper : public Napi::ObjectWrap<GreeterWrapper> {
public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);
  GreeterWrapper(const Napi::CallbackInfo &info);
  Napi::Value greet();

private:
  Napi::Value greet(const Napi::CallbackInfo &info);
  std::unique_ptr<Greeter> GreeterInstance;
};