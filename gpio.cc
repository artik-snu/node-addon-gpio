#include <node.h>
#include <v8.h>

#include "tizen-gpio.h"

using namespace v8;

void Hello(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  args.GetReturnValue().Set(String::NewFromUtf8(isolate, "Hello World"));
}

void SetPinMode(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);

  if (args.Length() < 2) {
    isolate->ThrowException(Exception::TypeError(
          String::NewFromUtf8(isolate, "Wrong number of arguments")));
    return;
  }

  if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
    isolate->ThrowException(Exception::TypeError(
          String::NewFromUtf8(isolate, "Wrong arguments")));
    return;
  }

  int value = set_pin_mode(args[0]->NumberValue(), args[1]->NumberValue());
  Local<Number> num = Number::New(isolate, value);

  args.GetReturnValue().Set(num);
} 

void GetPinMode(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);

  if (args.Length() < 1) {
    isolate->ThrowException(Exception::TypeError(
          String::NewFromUtf8(isolate, "Wrong number of arguments")));
    return;
  }

  if (!args[0]->IsNumber()) {
    isolate->ThrowException(Exception::TypeError(
          String::NewFromUtf8(isolate, "Wrong arguments")));
    return;
  }

  int value = get_pin_mode(args[0]->NumberValue());
  Local<Number> num = Number::New(isolate, value);

  args.GetReturnValue().Set(num);
}

void SetPinValue(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);

  if (args.Length() < 2) {
    isolate->ThrowException(Exception::TypeError(
          String::NewFromUtf8(isolate, "Wrong number of arguments")));
    return;
  }

  if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
    isolate->ThrowException(Exception::TypeError(
          String::NewFromUtf8(isolate, "Wrong arguments")));
    return;
  }

  int value = set_pin_value(args[0]->NumberValue(), args[1]->NumberValue());
  Local<Number> num = Number::New(isolate, value);

  args.GetReturnValue().Set(num);
}

void GetPinValue(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);

  if (args.Length() < 1) {
    isolate->ThrowException(Exception::TypeError(
          String::NewFromUtf8(isolate, "Wrong number of arguments")));
    return;
  }

  if (!args[0]->IsNumber()) {
    isolate->ThrowException(Exception::TypeError(
          String::NewFromUtf8(isolate, "Wrong arguments")));
    return;
  }

  int value = get_pin_value(args[0]->NumberValue());
  Local<Number> num = Number::New(isolate, value);

  args.GetReturnValue().Set(num);
}

void Init(Handle<Object> exports) {
  init_gpio();

  NODE_SET_METHOD(exports, "hello", Hello);
  NODE_SET_METHOD(exports, "setPinMode", SetPinMode);
  NODE_SET_METHOD(exports, "getPinMode", GetPinMode);
  NODE_SET_METHOD(exports, "setPinValue", SetPinValue);
  NODE_SET_METHOD(exports, "getPinValue", GetPinValue);
}

NODE_MODULE(gpio, Init)