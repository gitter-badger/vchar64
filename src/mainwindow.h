/****************************************************************************
Copyright 2015 Ricardo Quesada

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
****************************************************************************/

#pragma once

#include <QMainWindow>
#include <QString>
#include <QSettings>
#include <QVector>

QT_BEGIN_NAMESPACE
class QUndoView;
class QLabel;
QT_END_NAMESPACE

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    static constexpr int MAX_RECENT_FILES=20;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    Ui::MainWindow* getUi() const {
        return _ui;
    }

public slots:
    void previewConnected();
    void previewDisconnected();
    void documentWasModified();
    void updateWindow();
    void onCharIndexUpdated(int);
    void onMulticolorModeToggled(bool);
    void onTilePropertiesUpdated();
    bool openFile(const QString& fileName);
    void setErrorMessage(const QString& errorMessage);
    void onColorPropertiesUpdated(int pen);
    void onOpenRecentFileTriggered();

protected:
    void readSettings();
    void saveSettings();
    void createActions();
    void createDefaults();
    void createUndoView();
    void setupStatusBar();

    void updateRecentFiles();
    void setRecentFile(const QString& fileName);
    QStringList recentFiles() const;

    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;


private slots:

    void on_actionExit_triggered();
    void on_actionOpen_triggered();
    bool on_actionSaveAs_triggered();
    bool on_actionSave_triggered();
    void on_actionExport_triggered();
    void on_actionExportAs_triggered();
    void on_actionInvert_triggered();
    void on_actionFlipHorizontally_triggered();
    void on_actionFlipVertically_triggered();
    void on_actionRotate_triggered();
    void on_actionClearCharacter_triggered();
    void on_actionShiftLeft_triggered();
    void on_actionShiftRight_triggered();
    void on_actionShiftUp_triggered();
    void on_actionShiftDown_triggered();
    void on_actionCut_triggered();
    void on_actionCopy_triggered();
    void on_actionPaste_triggered();
    void on_actionReportBug_triggered();
    void on_actionAbout_triggered();
    void on_actionAboutQt_triggered();
    void on_actionClearRecentFiles_triggered();
    void on_actionEmptyProject_triggered();
    void on_actionC64DefaultUppercase_triggered();
    void on_actionC64DefaultLowercase_triggered();
    void on_actionTilesProperties_triggered();
    void on_actionXlinkConnection_triggered();
    void on_actionUndo_triggered();
    void on_actionRedo_triggered();
    void on_radioButton_background_clicked();
    void on_radioButton_foreground_clicked();
    void on_radioButton_multicolor1_clicked();
    void on_radioButton_multicolor2_clicked();

    void on_checkBox_multicolor_toggled(bool checked);

    void on_actionPalette_0_triggered();
    void on_actionPalette_1_triggered();
    void on_actionPalette_2_triggered();
    void on_actionPalette_3_triggered();
    void on_actionPalette_4_triggered();


    void on_actionDocumentation_triggered();

    void on_actionNext_Tile_triggered();
    void on_actionPrevious_Tile_triggered();

    void on_actionImport_VICE_snapshot_triggered();

    void on_actionReset_Layout_triggered();

private:

    bool maybeSave();
    void activateRadioButtonIndex(int pen);
    void activatePalette(int paletteIndex);

    QVector<QAction*> _recentFiles;

    Ui::MainWindow* _ui;
    QString _lastDir;
    QLabel* _labelCharIdx;
    QLabel* _labelTileIdx;
    QLabel* _labelSelectedColor;

    QSettings _settings;
};

