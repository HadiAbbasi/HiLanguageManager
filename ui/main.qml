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
        text: HiLanguageManager.getStringByKey("hello") + HiLanguageManager.immediate_changer
        x: enBtn.x
        y:410
        onClicked: {
            messageDialog.show(HiLanguageManager.getStringByKey("hello_world")+HiLanguageManager.immediate_changer)
        }
    }

    Button {
        id: quitBtn
        x: faBtn.x
        y: 410
        text: HiLanguageManager.getStringByKey("quit")+HiLanguageManager.immediate_changer
        onClicked: {
            Qt.quit();
        }
    }

    MessageDialog
    {
        id: messageDialog
        title: HiLanguageManager.getStringByKey("info")+HiLanguageManager.immediate_changer

        function show(caption)
        {
            messageDialog.text = caption;
            messageDialog.open();
        }
    }
}
