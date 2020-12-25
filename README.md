# HiLanguageManager
A Simple Qt tool for making Multi-Language Apps...

Now it's possible to change qml text language immediately by switching between languages!

```
//main.cpp
#include <iostream>
using namespace std;
#include <QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QMetaObject>
#include <QQmlContext>
#include <QDebug>

#include "include/hi/hilanguagemanager.hpp"

#define QML_REGISTER(classname,packagename,MAJORVERSION,minorversion) \
qmlRegisterType<classname>(packagename, MAJORVERSION, minorversion, #classname);
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
```

This is our json file of languages dictionary which contains all our required multi-language texts categorised by languages name and all texts have unique key!
you have to pass unique key to your textboxes + HiLanguageManager.immediate_changer
in this example we have to pass en|fa string for change in language!

```
{
    "en": {
        "quit": "Quit",
        "hello": "Hello",
        "info": "Info",
        "hello_world":"Hello World"
    },
    "fa": {
        "quit": "خروج",
        "hello": "سلام",
        "info": "اطلاعات",
        "hello_world":"سلام دنیا"
    }
}
```

and this is our  simple QML file (main.qml):

```
import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.14
import QtQuick.Dialogs 1.2

import hi 1.0

ApplicationWindow {
    id: appRoot
    title: "Hi Language Manager"

    Button {
        id: enBtn
        text: "English Lang"
        onClicked: {
            HiLanguageManager.language = "en"
        }
    }

    Button {
        id:  faBtn
        text: "زبان فارسی"
        onClicked: {
            HiLanguageManager.language = "fa"
        }
    }

    Button {
        id: showDialogBtn
        text: HiLanguageManager.getStringByKey("hello") + HiLanguageManager.immediate_changer
        onClicked: {
            messageDialog.show(HiLanguageManager.getStringByKey("hello_world")+HiLanguageManager.immediate_changer)
        }
    }

    Button {
        id: quitBtn
        text: HiLanguageManager.getStringByKey("quit")+HiLanguageManager.immediate_changer
        onClicked: {
            Qt.quit();
        }
    }
}

```

Be careful to change your text language immediately after switching between languages, you have to concat HiLanguageManager.immediate_changer to your text!
it's no matter where you concat it! so you can concat it at the begin or middle or end of your text!
in this example, we have used this class as singleton class whitout any additional objects!

for adding other languages, you have to edit lang.json:

```
{
    "en": {
        "hello": "Hello"
    },
    "fa": {
        "hello": "سلام"
    },
    "ru": {
         "hello": "Здравствуйте"
    },
    "arabic": {
        "hello":"مرحبا"
    }
}
```
As you can see, hello is  the common key between all words mean the same thing. then you can switch between languages using:

```
//main.qml
ApplicationWindow {
    //..
    //..
    //..
    Button {
        id: changeLangBtn
        onClicked {
            HiLanguageManager.language = "fa"
            //HiLanguageManager.language = "en"
            //HiLanguageManager.language = "ru"
            //HiLanguageManager.language = "arabic"
        }
    }
    Text {
        text: HiLanguageManager.getStringByKey("hello")+HiLanguageManager.immediate_changer
        //+HiLanguageManager.immediate_changer will make immediate switching by click on changeLangBtn!
    }
}
```
