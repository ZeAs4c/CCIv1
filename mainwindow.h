#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QPair>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_beginInstractionBtn_clicked();

    void on_endInstractionBtn_clicked();

    void on_bakingBtn_clicked();

    void on_sweetsBtn_clicked();

    void on_stuffingBtn_clicked();

    void on_deleteAllMenu_triggered();

    void on_powderBtn_clicked();

    void on_glazeBtn_clicked();

    void on_startProductionBtn_clicked();

    void on_endProductionBtn_clicked();

    void on_amountBtn_clicked();

    void on_doughPreparationBtn_clicked();

    void on_fillingPreparationBtn_clicked();

    void on_icingPreparationBtn_clicked();

    void on_powderPreparationBtn_clicked();

    void on_productionCycleBtn_clicked();

    void on_endProductionCycleBtn_clicked();

    void on_doughDivisionBtn_clicked();

    void on_putDoughMoldBtn_clicked();

    void on_sendDoughOvenBtn_clicked();

    void on_takeDoughOvenBtn_clicked();

    void on_pourStaffingBtn_clicked();

    void on_drizzleGlazeDoughBtn_clicked();

    void on_sprinkleProductBtn_clicked();

    void on_packProductBtn_clicked();

    void on_productMarkingBtn_clicked();

    void on_sendingStorageBtn_clicked();

    void on_makingCaramelSyrupBtn_clicked();

    void on_preparationCaramelMassBtn_clicked();

    void on_coolingCaramelMassBtn_clicked();

    void on_promCaramelMassBtn_clicked();

    void on_shapingCaramelBtn_clicked();

    void on_coolingCaramelBtn_clicked();

    void on_glossyCaramelBtn_clicked();

    void on_glossCreationBtn_clicked();

    void on_glossCreationEndBtn_clicked();

    void on_formationSolidFillingBtn_clicked();

    void on_fillFrostingBtn_clicked();

    void on_runInstrMenu_triggered();

    void m_decisionProcessing(QString e);

signals:
    void    currentIndexChanged(int index);

    void    currentIndexChanged(const QString &text);
    void textEdited(const QString &text);

private:
    Ui::MainWindow *ui;
    QString tracker;
    QString trackerComboBox;

    QString countEx;

    QString countStaffingOneThing;
    QString nameStaffingOneThing;

    QString countGlazeOneThing;
    QString nameGlazeOneThing;

    QString countPowderOneThing;
    QString namePowderOneThing;

    QString countGlossCreation;
    QString countGlossCreation1;
    QList<QPair<QString, QString>> wFileMap;

    bool bakingUse;
    bool sweetUse;

    bool StaffingUse;
    bool PowderUse;
    bool GlazeUse;
    bool preparationStaffing;
    bool preparationPowder;
    bool preparationGlaze;
    bool AmountUse;
    bool SweetStuffing;
    bool preparationDough;
    bool dividingDough;
    bool putDough;
    bool sendDough;
    bool getDough;
    bool productMarkingUse;
    bool packProductUse;
    bool sendingStorageUse;
    bool endProductionCycleUse;
    bool endProductionProcessUse;

    bool preparationCaramelSyrupUse;
    bool preparationCaramelMassUse;
    bool coolingCaramelMassUse;
    bool caramelMassFillingUse;
    bool formationCaramelUse;
    bool caramelCoolingUse;
    bool beginningGlossCreationUse;
    bool endGlossCreationUse;

    bool formationSolidFillingUse;
    bool pourLazeSolidFillingUse;

    bool bakingUseRepeat;
    bool sweetUseRepeat;
    bool StaffingUseRepeat;
    bool PowderUseRepeat;
    bool GlazeUseRepeat;

};
#endif // MAINWINDOW_H
