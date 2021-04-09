#include <QCoreApplication>
#include <QDir>
#include "settings.hpp"

Settings::Settings() : QSettings(path(), QSettings::IniFormat) {}

const QByteArray Settings::geometry() {
    return value(geometryKey(), QByteArray()).toByteArray();
}

void Settings::setGeometry(QByteArray geometry) {
    setValue(geometryKey(), geometry);
}

bool Settings::hasRecentFiles() {
    const int count = beginReadArray(recentFilesKey());
    endArray();
    return count > 0;
}

QStringList Settings::recentFiles() {
    QStringList result;
    const int count = beginReadArray(recentFilesKey());
    for (int i = 0; i < count; i++) {
        setArrayIndex(i);
        result.append(value(fileKey()).toString());
    }
    endArray();
    return result;
}

void Settings::putRecentFile(const QString path) {
    QStringList files = recentFiles();
    files.insert(0, path);
    const int count = std::min(files.size(), 5);
    beginWriteArray(recentFilesKey());
    for (int i = 0; i < count; ++i) {
        setArrayIndex(i);
        setValue(fileKey(), files.at(i));
    }
    endArray();
}

QString Settings::path() {
    return QCoreApplication::applicationDirPath() + "/settings.ini";
}

inline QString Settings::geometryKey() {
    return QString("geometry");
}

inline QString Settings::recentFilesKey() {
    return QString("recent");
}

inline QString Settings::fileKey() {
    return QString("file");
}



