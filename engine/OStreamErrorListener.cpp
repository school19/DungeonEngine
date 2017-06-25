//
// Created by Chaz on 6/22/2017.
//

#include "OStreamErrorListener.h"

OStreamErrorListener::OStreamErrorListener(std::shared_ptr<std::ostream> outputStream) : mOutputStream(outputStream)
{}

void OStreamErrorListener::onError(std::string msg) {
    (*mOutputStream.get()) << msg;
}

