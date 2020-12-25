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

#ifndef HILANGUAGEMANAGER_HPP
#define HILANGUAGEMANAGER_HPP

#include <QObject>
#include <iostream>
using namespace:: std;
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QDebug>

class HiLanguageManager : public QObject
{
    Q_OBJECT
public:
    Q_PROPERTY(QString  language READ getLanguage WRITE setLanguage NOTIFY languageChangedSi)
    Q_PROPERTY(QString  immediate READ getImmediate WRITE setImmediate NOTIFY languageChangedSi)
    explicit HiLanguageManager(QString modelFileDir, QString language = "en", QObject *parent = nullptr);
    void setLanguage(QString lang);
    QString getLanguage() const;
    void setImmediate(QString immediate);
    QString getImmediate() const;
    Q_INVOKABLE QString getString(QString key) const;
signals:
    void languageChangedSi(QString);
private:
    QString _lang;
    QString _immediate;
    QJsonObject _lang_json;
};

#endif // HILANGUAGEMANAGER_HPP
