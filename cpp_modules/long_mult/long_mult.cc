#include <napi.h>
#include "long_mult.h"

using namespace std;

string reverse(string a)
{
  int aLength = a.length();
  for (int i = 0; i < aLength / 2; i++)
  {
    swap(a[i], a[aLength - 1 - i]);
  }

  return a;
}

string longMult(string a, string b)
{
  string reversedRes = "";

  a = reverse(a);
  b = reverse(b);

  if (a.length() < b.length())
  {
    swap(a, b);
  }

  // I don't remember how to use pointers :(
  int res[100],
      tmp = 0, lastIndex = a.length() - 1 + b.length() - 1;
  for (int i = 0; i < 100; i++)
  {
    res[i] = 0;
  }

  for (int i = 0; i < b.length(); i++)
  {
    for (int j = 0; j < a.length(); j++)
    {
      int mult = (int(a[j]) - 48) * (int(b[i]) - 48) + tmp;

      tmp = 0;
      int sum = res[i + j] + mult;
      res[i + j] = (sum % 10);
      tmp = sum / 10;
    }

    if (tmp != 0)
    {
      res[i + a.length()] += tmp;
      tmp = 0;
      if (i == b.length() - 1)
      {
        lastIndex++;
      }
    }
  }

  string stringRes = "";
  for (lastIndex; lastIndex >= 0; lastIndex--)
  {
    stringRes.push_back(res[lastIndex] + '0');
  }
  return stringRes;
}

Napi::Value LongMult(const Napi::CallbackInfo &info)
{
  Napi::Env env = info.Env();

  if (info.Length() < 2)
  {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsString() || !info[1].IsString())
  {
    Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
    return env.Null();
  }

  string a = info[0].As<Napi::String>().ToString();
  string b = info[1].As<Napi::Number>().ToString();
  Napi::String res = Napi::String::New(env, longMult(a, b));

  return res;
}
