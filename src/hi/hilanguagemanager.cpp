#include "include/hi/hilanguagemanager.hpp"

HiLanguageManager::HiLanguageManager(QString modelFileDir ,QString language , QObject *parent) : QObject(parent)
{
    QFile jsonFile(modelFileDir);
    if(!jsonFile.open(QIODevice::ReadOnly))
    {
        qDebug() << "error: " << jsonFile.errorString();
    }
    QString jsonStr = (QString)jsonFile.readAll();
    jsonFile.close();
    QJsonDocument lang_json_doc = QJsonDocument().fromJson(jsonStr.toUtf8());
    _lang_json = lang_json_doc.object();
    setLanguage(language);
}

void HiLanguageManager::setLanguage(QString lang)
{
    if (_lang != lang && !_lang_json.isEmpty())
    {
        _lang = lang;
        emit languageChangedSi(_lang);
    }
}

QString HiLanguageManager::getLanguage() const
{
    return _lang;
}

void HiLanguageManager::setImmediate(QString immediate)
{
    _immediate = "";
}

QString HiLanguageManager::getImmediate() const
{
    return _immediate;
}

QString HiLanguageManager::getStringByKey(QString key) const
{
    if (!_lang_json.isEmpty() && !_lang_json[_lang].isNull())
    {
        return _lang_json[_lang].toObject()[key].toString();
    }
}
