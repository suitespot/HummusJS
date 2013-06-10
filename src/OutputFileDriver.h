/*
 Source File : OutputFileDriver.h
 
 
 Copyright 2013 Gal Kahana HummusJS
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
 http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

#pragma once

#include <node.h>

#include "EStatusCode.h"

#include <string>

class OutputFile;

class OutputFileDriver : public node::ObjectWrap
{
public:
    virtual ~OutputFileDriver();
    
    static void Init(v8::Handle<v8::Object> inExports); // to allow instantiation from the hummus object
    static v8::Handle<v8::Value> NewInstance(const v8::Arguments& args);
    static bool HasInstance(v8::Handle<v8::Value> inObject);
    
    PDFHummus::EStatusCode OpenFile(const std::string& inFilePath,bool inAppend);
    void SetFromOwnedFile(OutputFile* inFile);
    
private:
    OutputFileDriver();
    
    OutputFile* mOutputFileInstance;
    bool mOwnsInstance;
    
    static v8::Persistent<v8::Function> constructor;
    static v8::Persistent<v8::FunctionTemplate> constructor_template;
    static v8::Handle<v8::Value> New(const v8::Arguments& args);
    static v8::Handle<v8::Value> OpenFile(const v8::Arguments& args);
    static v8::Handle<v8::Value> CloseFile(const v8::Arguments& args);
    static v8::Handle<v8::Value> GetFilePath(const v8::Arguments& args);
    static v8::Handle<v8::Value> GetOutputStream(const v8::Arguments& args);
    
};