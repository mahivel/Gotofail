/*
Mahitha Velagaleti
Secure and Dependable Systems
Dr. Rabe
Assignment 1.1 Gotofail.
*/

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cstdint>

#define Y 0
#define N 1

using namespace std;

typedef int OSStatus;

bool isRSA = true;
uint8_t sign = 0;
uint16_t siglen = 0;
string hashctx = "hash";

int SSLFreeBuffer(string *hashval){
    return 0;
}


class SSLContext
{
public:
    int clientRandom;
    int signParm;

};


class SSLBuffer
{
public:

    int signedparams;
    int *hashCtx;

};


class SSLHashSHA1
{
public:
     static OSStatus update(string *, int );
     static OSStatus Final(string *, string *);

};

OSStatus SSLHashSHA1::update(string *hashCtx, int servRandom)
{
    return servRandom;
}

OSStatus SSLHashSHA1::Final(string *hashCtx, string *hashOut)
{
    if ((*hashOut).compare("Error") == 0)
        return 1;
    else
        return 0;
}


int serverRandom = 0;
string signedHashes = "\0";
string hashOut ="success" ;
OSStatus result = 0;



static OSStatus SSLVerifySignedServerKeyExchange(SSLContext *ctx, bool isRsa, SSLBuffer signedParams, uint8_t *signature, uint16_t signatureLen)
{
    OSStatus        err = 0;


    if ((err = SSLHashSHA1::update(&hashctx, serverRandom)) != 0)
        goto fail;
    if ((err = SSLHashSHA1::update(&hashctx, signedParams.signedparams)) != 0)
        goto fail;
        goto fail;
    if ((err = SSLHashSHA1::Final(&hashctx, &hashOut)) != 0)
        goto fail;

    fail:
    SSLFreeBuffer(&signedHashes);
    SSLFreeBuffer(&hashctx);
    return err;

}

void unittest()
{
    SSLBuffer y;
    SSLContext x;

    result = SSLVerifySignedServerKeyExchange(&x, isRSA, y, &sign, siglen);
    cout<< result <<endl;

    serverRandom = N;
    result = SSLVerifySignedServerKeyExchange(&x, isRSA, y, &sign, siglen);
    cout << result << endl;
    serverRandom = Y;

    y.signedparams = N;
    result = SSLVerifySignedServerKeyExchange(&x, isRSA, y, &sign, siglen);
    cout << result << endl;
    y.signedparams = Y;

    hashOut = "Error";
    result = SSLVerifySignedServerKeyExchange(&x, isRSA, y, &sign, siglen);
    cout << result << endl;
    hashOut = "success";

}

  int main()
  {
      unittest();
      return 0;
  }




