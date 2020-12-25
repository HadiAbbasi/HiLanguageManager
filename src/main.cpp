/*
  The MIT License (MIT)
  Copyright (c) 2020 Hadi Abbasi & Hamed Masafi & Kambiz Asadzadeh
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:
  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
 */

#include <iostream>
using namespace std;

#include <QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QMetaObject>
#include <QQmlContext>
#include <QDebug>

#include "include/common.hpp"
#include "include/hi/hilanguagemanager.hpp"

static QObject* create_singelton_object_LanguageTranslator(QQmlEngine *, QJSEngine *)
{
    return new HiLanguageManager(":/lang.json");
}

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QML_REGISTER_SINGLETON(HiLanguageManager,"hi",1,0,create_singelton_object_LanguageTranslator)

    QQmlApplicationEngine engine;
    engine.load(QUrl("qrc:/ui/main.qml"));
    if (engine.rootObjects().isEmpty())
        return -1;
    // QObject *item = engine.rootObjects()[0];

    return app.exec();
}
