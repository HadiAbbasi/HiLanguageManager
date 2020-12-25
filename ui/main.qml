import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.14
import QtQuick.Dialogs 1.2

import hi 1.0

ApplicationWindow {
    id: appRoot
    title: "Hi Language Manager"
    visible: true
    width: 700
    height: 700

    Image {
        id: img
        source: "qrc:/ui/View/img.png"
        x: (appRoot.width - img.width)/2
        y: 5
    }

    Button {
        id: enBtn
        text: "English Lang"
        x: appRoot.width/2 - enBtn.width-5
        y:310
        onClicked: {
            HiLanguageManager.language = "en"
        }
    }

    Button {
        id:  faBtn
        text: "زبان فارسی"
        x: appRoot.width/2 + 5
        y:310
        onClicked: {
            HiLanguageManager.language = "fa"
        }
    }

    Button {
        id: showDialogBtn
        text: HiLanguageManager.getString("hello") + HiLanguageManager.immediate
        x: enBtn.x
        y:410
        onClicked: {
            messageDialog.show(HiLanguageManager.getString("hello_world")+HiLanguageManager.immediate)
        }
    }

    Button {
        id: quitBtn
        x: faBtn.x
        y: 410
        text: HiLanguageManager.getString("quit")+HiLanguageManager.immediate
        onClicked: {
            Qt.quit();
        }
    }

    MessageDialog
    {
        id: messageDialog
        title: HiLanguageManager.getString("info")+HiLanguageManager.immediate

        function show(caption)
        {
            messageDialog.text = caption;
            messageDialog.open();
        }
    }
}
