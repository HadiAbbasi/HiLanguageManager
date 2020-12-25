# HiLanguageManager
این یک ابزار ساده برای ساخت نرم افزارهای چند زبانه تحت کیوت و کیو ام ال است

حالا تغییر سریع زبان نوشته های نرم افزارتان با سویچ روی زبان ممکن است

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

این فایل جیسن ما است که به صورت گروه بندی زبانی شامل رشته های مختلف زبانی ما است
شما باید کلید واحد یک رشته که مشترک بین تمام زبانها است را به همراه پروپرتی امدیت از کلاس های لنگویج منیجر ست کنید
در این مثال ما باید کلمه کلیدی فا یا ای ان  را برای سویچ زبان پاس کنیم

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

و این کد هم کد کیو ام ال است
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
        text: HiLanguageManager.getString("hello") + HiLanguageManager.immediate
        onClicked: {
            messageDialog.show(HiLanguageManager.getString("hello_world")+HiLanguageManager.immediate)
        }
    }

    Button {
        id: quitBtn
        text: HiLanguageManager.getString("quit")+HiLanguageManager.immediate
        onClicked: {
            Qt.quit();
        }
    }
}

```

در جریان باشید که برای تغییر سریع نوشته هایتان با سویچ زبان، باید در ابتدا یا وسط یا انتهای آن، پروپرتی امدیت از کلاس های لنگویج منیجر را کانکت کنید
اینکه در ابتدا یا وسط یا انتهایش بیفزایید مهم نیست
در مثال ما، این کلاس به صورت سینگلتن استفاده شده تا نیاز به نمونه سازی چند گانه از آن نباشد


برای افزودن زبانهای اضافی باید لنگ دات جیسن را ویرایش کنید

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
همانطوری که مشاهده می فرمایید، واژه هلو (سلام انگلیسی) کلید مشترک بین تمام هم معنی هایش در زبانهای مختلف است. می توانید به صورت زیر بین زبانهای مختلف سویچ کنید

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
        text: HiLanguageManager.getString("hello")+HiLanguageManager.immediate
        //+HiLanguageManager.immediate will make immediate switching possible by click on changeLangBtn!
    }
}
```
