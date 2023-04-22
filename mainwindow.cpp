#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "LoggingCategories.h"
#include <qcombobox.h>
#include <qlabel.h>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->sweetsBtn->setEnabled(false);
    ui->bakingBtn->setEnabled(false);
    ui->stuffingBtn->setEnabled(false);
    ui->powderBtn->setEnabled(false);
    ui->endInstractionBtn->setEnabled(false);
    ui->glazeBtn->setEnabled(false);
    ui->startProductionBtn->setEnabled(false);
    ui->endProductionBtn->setEnabled(false);
    ui->amountBtn->setEnabled(false);
    ui->doughPreparationBtn->setEnabled(false);
    ui->fillingPreparationBtn->setEnabled(false);
    ui->icingPreparationBtn->setEnabled(false);
    ui->powderPreparationBtn->setEnabled(false);

    ui->productionCycleBtn->setEnabled(false);
    ui->endProductionCycleBtn->setEnabled(false);
    ui->doughDivisionBtn->setEnabled(false);
    ui->putDoughMoldBtn->setEnabled(false);
    ui->sendDoughOvenBtn->setEnabled(false);
    ui->takeDoughOvenBtn->setEnabled(false);
    ui->pourStaffingBtn->setEnabled(false);
    ui->drizzleGlazeDoughBtn->setEnabled(false);
    ui->sprinkleProductBtn->setEnabled(false);
    ui->packProductBtn->setEnabled(false);
    ui->productMarkingBtn->setEnabled(false);
    ui->sendingStorageBtn->setEnabled(false);

    ui->coolingCaramelBtn->setEnabled(false);
    ui->coolingCaramelMassBtn->setEnabled(false);
    ui->glossyCaramelBtn->setEnabled(false);
    ui->makingCaramelSyrupBtn->setEnabled(false);
    ui->preparationCaramelMassBtn->setEnabled(false);
    ui->promCaramelMassBtn->setEnabled(false);
    ui->shapingCaramelBtn->setEnabled(false);

    ui->glossCreationBtn->setEnabled(false);
    ui->glossCreationEndBtn->setEnabled(false);

    ui->fillFrostingBtn->setEnabled(false);
    ui->formationSolidFillingBtn->setEnabled(false);

    StaffingUse = false;
    PowderUse = false;
    GlazeUse = false;
    AmountUse = false;
    preparationStaffing = false;
    preparationPowder = false;
    preparationGlaze = false;
    bakingUse = false;
    sweetUse = false;

    preparationDough = false;
    dividingDough = false;
    putDough = false;
    sendDough = false;
    getDough = false;
    productMarkingUse = false;
    packProductUse = false;
    sendingStorageUse = false;
    endProductionCycleUse = false;
    endProductionProcessUse = false;

    preparationCaramelSyrupUse = false;
    preparationCaramelMassUse = false;
    coolingCaramelMassUse = false;
    caramelMassFillingUse = false;
    formationCaramelUse = false;
    caramelCoolingUse = false;
    beginningGlossCreationUse = false;
    endGlossCreationUse = false;

    formationSolidFillingUse = false;
    pourLazeSolidFillingUse = false;

    countEx = "";
    countStaffingOneThing = "";
    countGlazeOneThing = "";
    countPowderOneThing = "";
    countGlossCreation = "";
    countGlossCreation1 = "";
    SweetStuffing = false;

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_beginInstractionBtn_clicked()
{
    QLabel* beginInstrLbl = new QLabel(ui->beginInstractionBtn->text()+":");
    QListWidgetItem* itemBeginInstr = new QListWidgetItem( ui->confectioneryFieldList );
    ui->confectioneryFieldList->setItemWidget( itemBeginInstr,beginInstrLbl);
    qInfo(logInfo()) << beginInstrLbl->text();
    wFileMap.append(qMakePair(QString("beginInstrLbl"), beginInstrLbl->text()));
    ui->beginInstractionBtn->setEnabled(false);
    ui->sweetsBtn->setEnabled(true);
    ui->bakingBtn->setEnabled(true);
    ui->stuffingBtn->setEnabled(true);
    ui->powderBtn->setEnabled(true);
    ui->endInstractionBtn->setEnabled(true);
    ui->glazeBtn->setEnabled(true);
    ui->startProductionBtn->setEnabled(true);
    ui->endProductionBtn->setEnabled(false);
}


void MainWindow::on_endInstractionBtn_clicked()
{
    try{
    if(!endProductionProcessUse){
       QString error = "Закройте процесс производства!";
       qCritical(logError()) << error;
       throw error;
    }
    QLabel* endInstrLbl = new QLabel(ui->endInstractionBtn->text()+".");
    QListWidgetItem* itemEndInstr = new QListWidgetItem( ui->confectioneryFieldList );
    qInfo(logInfo()) << endInstrLbl->text();
    wFileMap.append(qMakePair(QString("endInstrLbl"), endInstrLbl->text()));
    ui->confectioneryFieldList->setItemWidget( itemEndInstr,endInstrLbl);
     ui->sweetsBtn->setEnabled(false);
     ui->bakingBtn->setEnabled(false);
     ui->stuffingBtn->setEnabled(false);
     ui->powderBtn->setEnabled(false);
     ui->endInstractionBtn->setEnabled(false);
     ui->glazeBtn->setEnabled(false);
     ui->startProductionBtn->setEnabled(false);
     ui->endProductionBtn->setEnabled(false);
     ui->amountBtn->setEnabled(false);
     ui->doughPreparationBtn->setEnabled(false);
     ui->fillingPreparationBtn->setEnabled(false);
     ui->icingPreparationBtn->setEnabled(false);
     ui->powderPreparationBtn->setEnabled(false);
     ui->productionCycleBtn->setEnabled(false);
     ui->endProductionCycleBtn->setEnabled(false);
     ui->doughDivisionBtn->setEnabled(false);
     ui->putDoughMoldBtn->setEnabled(false);
     ui->sendDoughOvenBtn->setEnabled(false);
     ui->takeDoughOvenBtn->setEnabled(false);
     ui->pourStaffingBtn->setEnabled(false);
     ui->drizzleGlazeDoughBtn->setEnabled(false);
     ui->sprinkleProductBtn->setEnabled(false);
     ui->packProductBtn->setEnabled(false);
     ui->productMarkingBtn->setEnabled(false);
     ui->sendingStorageBtn->setEnabled(false);
     ui->coolingCaramelBtn->setEnabled(false);
     ui->coolingCaramelMassBtn->setEnabled(false);
     ui->glossyCaramelBtn->setEnabled(false);
     ui->makingCaramelSyrupBtn->setEnabled(false);
     ui->preparationCaramelMassBtn->setEnabled(false);
     ui->promCaramelMassBtn->setEnabled(false);
     ui->shapingCaramelBtn->setEnabled(false);
     ui->glossCreationBtn->setEnabled(false);
     ui->glossCreationEndBtn->setEnabled(false);
     ui->fillFrostingBtn->setEnabled(false);
     ui->formationSolidFillingBtn->setEnabled(false);
     StaffingUse = false;
     PowderUse = false;
     GlazeUse = false;
     AmountUse = false;
     preparationStaffing = false;
     preparationPowder = false;
     preparationGlaze = false;
     bakingUse = false;
     sweetUse = false;
     SweetStuffing = false;
     endProductionCycleUse = false;
     endProductionProcessUse = false;
     preparationCaramelSyrupUse = false;
     preparationCaramelMassUse = false;
     coolingCaramelMassUse = false;
     caramelMassFillingUse = false;
     formationCaramelUse = false;
     caramelCoolingUse = false;
     beginningGlossCreationUse = false;
     endGlossCreationUse = false;

     formationSolidFillingUse = false;
     pourLazeSolidFillingUse = false;

     preparationDough = false;
     dividingDough = false;
     putDough = false;
     sendDough = false;
     getDough = false;
     productMarkingUse = false;
     packProductUse = false;
     sendingStorageUse = false;
    }catch(QString e){
            m_decisionProcessing(e);
        }
}


void MainWindow::on_bakingBtn_clicked()
{
    QWidget* wgtBaking = new QWidget;
    QComboBox *boxBaking = new QComboBox();
    boxBaking ->addItem("Пончик");
    boxBaking ->addItem("Эклер");
    boxBaking ->addItem("Круассан");
    QLabel* bakingLbl = new QLabel(ui->bakingBtn->text()+":");
    QHBoxLayout *bakingLt = new QHBoxLayout();
    boxBaking->setCurrentIndex(-1);
    connect( boxBaking, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),[=](int index){
        if((boxBaking->itemText(index)=="Пончик")||(boxBaking->itemText(index)=="Эклер")||(boxBaking->itemText(index)=="Круассан")){
            trackerComboBox = boxBaking->itemText(index);
            boxBaking->setEnabled(false);
            qInfo(logInfo()) << bakingLbl->text()+" "+trackerComboBox;
            wFileMap.append(qMakePair(QString("bakingLbl"), bakingLbl->text()+" "+trackerComboBox));
            bakingUse = true;
            ui->bakingBtn->setEnabled(false);
        }
    });
    bakingLt->addWidget(bakingLbl);
    bakingLt->addWidget(boxBaking);
    QListWidgetItem* itemBaking = new QListWidgetItem( ui->confectioneryFieldList );
    wgtBaking->setLayout( bakingLt );
    itemBaking->setSizeHint(wgtBaking->sizeHint());
    ui->confectioneryFieldList->setItemWidget(itemBaking,wgtBaking);
    ui->sweetsBtn->setEnabled(false);

    tracker = "baking";
}


void MainWindow::on_sweetsBtn_clicked()
{
    QWidget* wgtSweets = new QWidget;
    QComboBox *boxSweets = new QComboBox();
    boxSweets ->addItem("Ледeнец");
    boxSweets ->addItem("Шоколадные шарики");
    QLabel* sweetsLbl = new QLabel(ui->sweetsBtn->text()+":");
    QHBoxLayout *sweetsLt = new QHBoxLayout();
    boxSweets->setCurrentIndex(-1);
    connect(  boxSweets, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),[=](int index){
        if( boxSweets->itemText(index)=="Ледeнец"){
            trackerComboBox = "Леденец";
            boxSweets->setEnabled(false);
            ui->powderBtn->setEnabled(false);
            ui->glazeBtn->setEnabled(false);
            sweetUse = true;
        }
        if( boxSweets->itemText(index)=="Шоколадные шарики"){
            trackerComboBox = "Шоколадные шарики";
            boxSweets->setEnabled(false);
             boxSweets->setEnabled(false);
             sweetUse = true;
        }
        qInfo(logInfo()) << sweetsLbl->text()+" "+trackerComboBox;
        wFileMap.append(qMakePair(QString("sweetsLbl"), sweetsLbl->text()+" "+trackerComboBox));
        ui->sweetsBtn->setEnabled(false);
    });
    sweetsLt->addWidget(sweetsLbl);
    sweetsLt->addWidget(boxSweets);
    QListWidgetItem* itemSweets = new QListWidgetItem( ui->confectioneryFieldList );
    wgtSweets->setLayout( sweetsLt );
    itemSweets->setSizeHint(wgtSweets->sizeHint());
    ui->confectioneryFieldList->setItemWidget(itemSweets,wgtSweets);
    ui->bakingBtn->setEnabled(false);

    tracker = "sweets";

}


void MainWindow::on_stuffingBtn_clicked()
{
    try{
    if(!bakingUse && !sweetUse){
       QString error = "Вам стоит выбрать изделие!";
       qCritical(logError()) << error;
       throw error;
    }
    QWidget* wgtStuffing = new QWidget;
    QComboBox *boxStuffing = new QComboBox();
    QLineEdit *textLineStuffing = new QLineEdit();
    textLineStuffing->setValidator( new QIntValidator(0, 10000, this) );
    QLabel* stuffingLbl = new QLabel(ui->stuffingBtn->text()+":");
    QLabel* mlLbl = new QLabel("объем в миллилитрах на одну единицу изделия");
    QHBoxLayout *stuffingLt = new QHBoxLayout();
    if(tracker == "baking"){
        boxStuffing->addItem("Молочный шоколад");
        boxStuffing->addItem("Горький шоколад");
        boxStuffing->addItem("Шоколад молочный с орехами");
        boxStuffing->addItem("Шоколад тёмный с орехами");
        boxStuffing->addItem("Сгущённое молоко");
        boxStuffing->addItem("Вареное молоко");
    }
    if(tracker == "sweets"){
        if(trackerComboBox == "Леденец"){
            boxStuffing->addItem("Ароматизированный клубникой сахар");
        }
        if(trackerComboBox == "Шоколадные шарики"){
            boxStuffing->addItem("Молочный шоколад");
            boxStuffing->addItem("Горький шоколад");
            boxStuffing->addItem("Шоколад молочный с орехами");
            boxStuffing->addItem("Шоколад тёмный с орехами");
            boxStuffing->addItem("Нуга");
        }
    }
    boxStuffing->setCurrentIndex(-1);

    connect( textLineStuffing, static_cast<void(QLineEdit::*)(const QString &text)>(&QLineEdit::textEdited),[=]{
        countStaffingOneThing = textLineStuffing->text();
        qInfo(logInfo()) <<mlLbl->text() + " " + countStaffingOneThing;
        StaffingUse = true;
        SweetStuffing = true;
     });
    connect( boxStuffing, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),[=](int index){
        if(( boxStuffing->itemText(index)=="Ароматизированный клубникой сахар")||
                ( boxStuffing->itemText(index)=="Молочный шоколад")||( boxStuffing->itemText(index)=="Горький шоколад")
                ||( boxStuffing->itemText(index)=="Шоколад молочный с орехами")
                ||( boxStuffing->itemText(index)=="Шоколад тёмный с орехами")||( boxStuffing->itemText(index)=="Сгущённое молоко")
                ||( boxStuffing->itemText(index)=="Нуга")
                ||( boxStuffing->itemText(index)=="Вареное молоко")){
            nameStaffingOneThing = boxStuffing->itemText(index);
            qInfo(logInfo()) << stuffingLbl->text()+" "+nameStaffingOneThing;
            wFileMap.append(qMakePair(QString("stuffingLbl"), stuffingLbl->text()+" "+nameStaffingOneThing));
            boxStuffing->setEnabled(false);
            ui->stuffingBtn->setEnabled(false);
        }
     });
    stuffingLt ->addWidget(stuffingLbl);
    stuffingLt ->addWidget(boxStuffing);
    stuffingLt ->addWidget(mlLbl);
    stuffingLt ->addWidget(textLineStuffing);
    QListWidgetItem* itemStuffing = new QListWidgetItem( ui->confectioneryFieldList );
    wgtStuffing->setLayout( stuffingLt );
    itemStuffing->setSizeHint(wgtStuffing->sizeHint());

    ui->confectioneryFieldList->setItemWidget(itemStuffing,wgtStuffing);
    }catch(QString e){
            m_decisionProcessing(e);
        }

}

void MainWindow::on_powderBtn_clicked()
{
    try{
    if(!bakingUse && !sweetUse){
       QString error = "Вам стоит выбрать изделие!";
       qCritical(logError()) << error;
       throw error;
    }
    QWidget* wgtPowder = new QWidget;
    QComboBox *boxPowder = new QComboBox();
    QLineEdit *textLinePowder = new QLineEdit();
    textLinePowder->setValidator( new QIntValidator(0, 10000, this) );
    QLabel* powderLbl = new QLabel(ui->powderBtn->text()+":");
    QLabel* grLbl = new QLabel("вес в граммах на одну единицу изделия");
    QHBoxLayout *powderLt = new QHBoxLayout();

    if(tracker == "baking"){
        boxPowder->addItem("Сахарная пудра");
        boxPowder->addItem("Шоколадная крошка");
        boxPowder->addItem("Сахар");
    }
    if(tracker == "sweets"){
        boxPowder->addItem("Шоколадная крошка");
    }
    connect( boxPowder, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),[=](int index){
        if(( boxPowder->itemText(index)=="Сахарная пудра")||
                ( boxPowder->itemText(index)=="Шоколадная крошка")||( boxPowder->itemText(index)=="Сахар")){
            namePowderOneThing = boxPowder->itemText(index);
             boxPowder->setEnabled(false);
             qInfo(logInfo()) << powderLbl->text()+" "+namePowderOneThing;
             wFileMap.append(qMakePair(QString("powderLbl"), powderLbl->text()+" "+namePowderOneThing));
             ui->powderBtn->setEnabled(false);
        }
     });
    connect( textLinePowder, static_cast<void(QLineEdit::*)(const QString &text)>(&QLineEdit::textEdited),[=]{
        countPowderOneThing = textLinePowder->text();
        qInfo(logInfo()) <<grLbl->text() + " " + countPowderOneThing;
        PowderUse = true;
     });
    boxPowder->setCurrentIndex(-1);

    powderLt->addWidget(powderLbl);
    powderLt->addWidget(boxPowder);
    powderLt->addWidget(grLbl);
    powderLt->addWidget(textLinePowder);

    QListWidgetItem* itemPowder = new QListWidgetItem( ui->confectioneryFieldList );
    wgtPowder->setLayout(powderLt);
    itemPowder->setSizeHint(wgtPowder->sizeHint());
    ui->confectioneryFieldList->setItemWidget(itemPowder,wgtPowder);

    }catch(QString e){
            m_decisionProcessing(e);
        }
}

void MainWindow::on_glazeBtn_clicked()
{
    try{
    if(!bakingUse && !sweetUse){
       QString error = "Вам стоит выбрать изделие!";
       qCritical(logError()) << error;
       throw error;
    }
    GlazeUse = true;
    QWidget* wgtGlaze = new QWidget;
    QComboBox *boxGlaze = new QComboBox();
    QLineEdit *textLineGlaze = new QLineEdit();
    textLineGlaze->setValidator( new QIntValidator(0, 10000, this) );
    QLabel* glazeLbl = new QLabel(ui->glazeBtn->text()+":");
    QLabel* mlLbl = new QLabel("объем в миллилитрах на одну единицу изделия");
    QHBoxLayout *glazeLt = new QHBoxLayout();

    if(tracker == "baking"){
        boxGlaze->addItem("Шоколад");
        boxGlaze->addItem("Белый шоколад");
        boxGlaze->addItem("Клубничная глазурь");
        boxGlaze->addItem("Сахарная глазурь");
    }
    if(tracker == "sweets"){
        boxGlaze->addItem("Шоколад");
        boxGlaze->addItem("Белый шоколад");
    }
    connect( boxGlaze, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),[=](int index){
        if(( boxGlaze->itemText(index)=="Шоколад")||
                ( boxGlaze->itemText(index)=="Белый шоколад")||( boxGlaze->itemText(index)=="Клубничная глазурь")
                ||( boxGlaze->itemText(index)=="Сахарная глазурь")){
            nameGlazeOneThing = boxGlaze->itemText(index);
             boxGlaze->setEnabled(false);
             qInfo(logInfo()) << glazeLbl->text()+" "+nameGlazeOneThing;
             wFileMap.append(qMakePair(QString("glazeLbl"), glazeLbl->text()+" "+nameGlazeOneThing));
             ui->glazeBtn->setEnabled(false);
        }
     });
    connect( textLineGlaze, static_cast<void(QLineEdit::*)(const QString &text)>(&QLineEdit::textEdited),[=]{
        countGlazeOneThing = textLineGlaze->text();
        qInfo(logInfo()) <<mlLbl->text() + " " + countGlazeOneThing;
        GlazeUse = true;
     });
    boxGlaze->setCurrentIndex(-1);


    glazeLt->addWidget(glazeLbl);
    glazeLt->addWidget(boxGlaze);
    glazeLt->addWidget(mlLbl);
    glazeLt->addWidget(textLineGlaze);

    QListWidgetItem* itemGlaze = new QListWidgetItem( ui->confectioneryFieldList );
    wgtGlaze->setLayout(glazeLt);
    itemGlaze->setSizeHint(wgtGlaze->sizeHint());
    ui->confectioneryFieldList->setItemWidget(itemGlaze,wgtGlaze);

    }catch(QString e){
            m_decisionProcessing(e);
        }
}

void MainWindow::on_startProductionBtn_clicked()
{
    QLabel* startProductLbl = new QLabel(" "+ui->startProductionBtn->text()+":");
    QListWidgetItem* itemStartProduction = new QListWidgetItem( ui->confectioneryFieldList );
    qInfo(logInfo()) << startProductLbl->text();
    wFileMap.append(qMakePair(QString("startProductLbl"), startProductLbl->text()));
    ui->confectioneryFieldList->setItemWidget( itemStartProduction,startProductLbl);
    if(trackerComboBox == "Леденец"){
        ui->glossCreationBtn->setEnabled(true);
        ui->glossCreationEndBtn->setEnabled(true);
        ui->makingCaramelSyrupBtn->setEnabled(true);
        ui->coolingCaramelMassBtn->setEnabled(true);
        ui->preparationCaramelMassBtn->setEnabled(true);
        ui->shapingCaramelBtn->setEnabled(true);
        ui->promCaramelMassBtn->setEnabled(true);
        ui->coolingCaramelBtn->setEnabled(true);
    }else if(trackerComboBox == "Шоколадные шарики"){
        ui->fillingPreparationBtn->setEnabled(true);
        ui->icingPreparationBtn->setEnabled(true);
        ui->powderPreparationBtn->setEnabled(true);
        ui->productionCycleBtn->setEnabled(true);
    }
    else{
    ui->doughPreparationBtn->setEnabled(true);
    ui->fillingPreparationBtn->setEnabled(true);
    ui->icingPreparationBtn->setEnabled(true);
    ui->powderPreparationBtn->setEnabled(true);
    ui->productionCycleBtn->setEnabled(true);
    }
    ui->productionCycleBtn->setEnabled(true);
    ui->endProductionBtn->setEnabled(true);
    ui->amountBtn->setEnabled(true);
    ui->startProductionBtn->setEnabled(false);
}

void MainWindow::on_endProductionBtn_clicked()
{
    try{
    if(!endProductionCycleUse){
       QString error = "Закройте цикл производства!";
       qCritical(logError()) << error;
       throw error;
    }
    QLabel* endProductLbl = new QLabel(" "+ui->endProductionBtn->text());
    QListWidgetItem* itemEndProduction = new QListWidgetItem( ui->confectioneryFieldList );
    qInfo(logInfo()) << endProductLbl->text();
    wFileMap.append(qMakePair(QString("endProductLbl"), endProductLbl->text()));
    ui->confectioneryFieldList->setItemWidget( itemEndProduction,endProductLbl);
    ui->endProductionBtn->setEnabled(false);
    ui->amountBtn->setEnabled(false);
    ui->doughPreparationBtn->setEnabled(false);
    ui->fillingPreparationBtn->setEnabled(false);
    ui->icingPreparationBtn->setEnabled(false);
    ui->powderPreparationBtn->setEnabled(false);
    ui->productionCycleBtn->setEnabled(false);
    ui->glossCreationBtn->setEnabled(false);
    ui->glossCreationEndBtn->setEnabled(false);
    ui->makingCaramelSyrupBtn->setEnabled(false);
    ui->coolingCaramelMassBtn->setEnabled(false);
    ui->preparationCaramelMassBtn->setEnabled(false);
    ui->shapingCaramelBtn->setEnabled(false);
    ui->promCaramelMassBtn->setEnabled(false);
    ui->coolingCaramelBtn->setEnabled(false);
    endProductionProcessUse = true;
    ui->endProductionBtn->setEnabled(false);
    }catch(QString e){
            m_decisionProcessing(e);
        }
}

void MainWindow::on_amountBtn_clicked()
{
    QWidget* wgtAmont = new QWidget;
    QLabel* amountLbl = new QLabel("  "+ui->amountBtn->text()+" изделия "+"<<"+trackerComboBox+">>"+":");
    wFileMap.append(qMakePair(QString("amountLbl"), amountLbl->text()));
    QLineEdit *textLineAmount = new QLineEdit();
    textLineAmount->setValidator( new QIntValidator(0, 10000, this) );
    QHBoxLayout *amountLt = new QHBoxLayout();
    connect( textLineAmount, static_cast<void(QLineEdit::*)(const QString &text)>(&QLineEdit::textEdited),[=]{
        countEx = textLineAmount->text();
         qInfo(logInfo()) << amountLbl->text() + " " + countEx;
         AmountUse = true;
     });
    amountLt->addWidget(amountLbl);
    amountLt->addWidget(textLineAmount);
    QListWidgetItem* itemAmount = new QListWidgetItem( ui->confectioneryFieldList );
    wgtAmont->setLayout(amountLt);
    itemAmount->setSizeHint(wgtAmont->sizeHint());
    ui->confectioneryFieldList->setItemWidget(itemAmount,wgtAmont);
    ui->amountBtn->setEnabled(false);
}

void MainWindow::on_glossCreationBtn_clicked()
{
    QWidget* wgtGlossCreation = new QWidget;
    QLabel* glossCreation0Lbl = new QLabel("  Создание глянца:");
    qInfo(logInfo()) << glossCreation0Lbl->text();

    QLabel* glossCreationLbl = new QLabel("  Расплавленные - Парафин:");
    wFileMap.append(qMakePair(QString("glossCreation0Lbl"), glossCreation0Lbl->text()));
    QLineEdit *textGlossCreation = new QLineEdit();
    QLineEdit *textGlossCreation1 = new QLineEdit();
    textGlossCreation->setValidator( new QIntValidator(0, 10000, this) );
    textGlossCreation1->setValidator( new QIntValidator(0, 10000, this) );
    QLabel* glossCreation1Lbl = new QLabel(" миллилитров на всю партию леденцов");
    QLabel* glossCreation15Lbl = new QLabel("  Воск: ");

    QLabel* glossCreation2Lbl = new QLabel(" миллилитров на всю партию леденцов");
    QHBoxLayout *glossCreationLt = new QHBoxLayout();
    QHBoxLayout *glossCreationLt1 = new QHBoxLayout();
    QVBoxLayout *glossCreationVLt = new QVBoxLayout();
    connect( textGlossCreation, static_cast<void(QLineEdit::*)(const QString &text)>(&QLineEdit::textEdited),[=]{
        countGlossCreation = textGlossCreation->text();
        qInfo(logInfo()) << glossCreationLbl->text()+" "+countGlossCreation;
     });
    connect( textGlossCreation1, static_cast<void(QLineEdit::*)(const QString &text)>(&QLineEdit::textEdited),[=]{
        countGlossCreation1 = textGlossCreation1->text();
        qInfo(logInfo()) <<glossCreation1Lbl->text() + " " + countGlossCreation1 +  glossCreation2Lbl->text();
        beginningGlossCreationUse = true;
     });

    glossCreationLt->addWidget(glossCreationLbl);
    glossCreationLt->addWidget(textGlossCreation);
    glossCreationLt->addWidget(glossCreation1Lbl);
    glossCreationLt1->addWidget(glossCreation15Lbl);
    glossCreationLt1->addWidget(textGlossCreation1);
    glossCreationLt1->addWidget(glossCreation2Lbl);
    glossCreationVLt->addWidget(glossCreation0Lbl);
    glossCreationVLt->addLayout(glossCreationLt);
     glossCreationVLt->addLayout(glossCreationLt1);

    QListWidgetItem* itemGlossCreation = new QListWidgetItem( ui->confectioneryFieldList );
    wgtGlossCreation->setLayout(glossCreationVLt);
    itemGlossCreation->setSizeHint(wgtGlossCreation->sizeHint());
    ui->confectioneryFieldList->setItemWidget(itemGlossCreation,wgtGlossCreation);
    ui->glossCreationBtn->setEnabled(false);
}

void MainWindow::on_glossCreationEndBtn_clicked()
{
    try{
    if(!beginningGlossCreationUse){
       QString error = "Начните создание глянца!";
       qCritical(logError()) << error;
       throw error;
    }
    QWidget* wgtGlossCreationEnd = new QWidget;
    QLabel* glossCreationEndLbl = new QLabel("  Растительное масло: "+QString::number(countGlossCreation.toInt()+countGlossCreation1.toInt())+" миллилитров на всю партию леденцов. Полученное перемешивается в производственной ёмкости.");
    QLabel* glossCreationEnd0Lbl = new QLabel("  Конец создания глянца");
    wFileMap.append(qMakePair(QString("glossCreationEndLbl"), glossCreationEndLbl->text()+"\n"+glossCreationEnd0Lbl->text()));
    QVBoxLayout *glossCreationEndLt = new QVBoxLayout();
    qInfo(logInfo()) << glossCreationEndLbl->text();
    qInfo(logInfo()) << glossCreationEnd0Lbl->text();
    glossCreationEndLt->addWidget(glossCreationEndLbl);
    glossCreationEndLt->addWidget(glossCreationEnd0Lbl);

    QListWidgetItem* itemGlossCreationEnd = new QListWidgetItem( ui->confectioneryFieldList );
    wgtGlossCreationEnd->setLayout(glossCreationEndLt);
    itemGlossCreationEnd ->setSizeHint(wgtGlossCreationEnd->sizeHint());
    ui->confectioneryFieldList->setItemWidget(itemGlossCreationEnd,wgtGlossCreationEnd);
    endGlossCreationUse = true;
    ui->glossCreationEndBtn->setEnabled(false);
    }catch(QString e){
        m_decisionProcessing(e);
    }
}

void MainWindow::on_doughPreparationBtn_clicked()
{
    try{
    if(!AmountUse){
       QString error = "Количество изделий, которые надо изготовить не было выбрано!";
       qCritical(logError()) << error;
       throw error;
    }
    QWidget* wgtDoughPreparation = new QWidget;
    QLabel* doughPreparationLbl = new QLabel("  "+ui->doughPreparationBtn->text()+" на "+countEx+" штук предполагает выполнение следующих действий:");
    QLabel* preparationOfRawMaterialsLbl = new QLabel(" 1. Подготовка основного и дополнительного сырья на изделие <<" +trackerComboBox +">>.");
    QLabel* dosingLbl = new QLabel(" 2. Дозирование по объему и массе.");
    QLabel* doughKneading = new QLabel(" 3. Замес теста.");
    QLabel* doughFermentationLbl = new QLabel(" 4. Брожение теста.");
    wFileMap.append(qMakePair(QString("doughPreparationLbl"), doughPreparationLbl->text()+"\n"+preparationOfRawMaterialsLbl->text()+"\n"+dosingLbl->text()+"\n"+doughKneading->text()+"\n"+doughFermentationLbl->text()));
    qInfo(logInfo()) << doughPreparationLbl->text();
    qInfo(logInfo()) << preparationOfRawMaterialsLbl->text();
    qInfo(logInfo()) << dosingLbl->text();
    qInfo(logInfo()) << doughKneading->text();
    qInfo(logInfo()) << doughFermentationLbl->text();
    QVBoxLayout *doughPreparationLt = new QVBoxLayout();
    doughPreparationLt->addWidget(doughPreparationLbl);
    doughPreparationLt->addWidget(preparationOfRawMaterialsLbl);
    doughPreparationLt->addWidget(dosingLbl);
    doughPreparationLt->addWidget( doughKneading);
    doughPreparationLt->addWidget( doughFermentationLbl);

    QListWidgetItem* itemDoughPreparation = new QListWidgetItem( ui->confectioneryFieldList );
    wgtDoughPreparation->setLayout(doughPreparationLt);
    itemDoughPreparation->setSizeHint(wgtDoughPreparation->sizeHint());
    ui->confectioneryFieldList->setItemWidget(itemDoughPreparation,wgtDoughPreparation);
    preparationDough = true;
    ui->doughPreparationBtn->setEnabled(false);
    }catch(QString e){
        m_decisionProcessing(e);
    }

}

void MainWindow::on_fillingPreparationBtn_clicked()
{
    try{
    if(!StaffingUse){
       QString error = "Начинка не была выбрана!";
       qCritical(logError()) << error;
       throw error;
    }
    if(countStaffingOneThing == ""){
       QString error = "Количество начинки не было выбрано!";
       qCritical(logError()) << error;
       throw error;
    }
    if(!AmountUse){
       QString error = "Количество изделий, которые надо изготовить не было выбрано!";
       qCritical(logError()) << error;
       throw error;
    }
    QWidget* wgtFillingPreparation = new QWidget;
    QLabel* fillingPreparationLbl = new QLabel("  "+ui->fillingPreparationBtn->text()+" <<"+nameStaffingOneThing+">> на "+QString::number(countEx.toInt()*countStaffingOneThing.toInt())+" мл.");
    qInfo(logInfo()) << fillingPreparationLbl->text();
    wFileMap.append(qMakePair(QString("fillingPreparationLbl"), fillingPreparationLbl->text()));
    QVBoxLayout *fillingPreparationLt = new QVBoxLayout();
    fillingPreparationLt->addWidget(fillingPreparationLbl);

    QListWidgetItem* itemFillingPreparation = new QListWidgetItem( ui->confectioneryFieldList );
    wgtFillingPreparation->setLayout(fillingPreparationLt);
    itemFillingPreparation->setSizeHint(wgtFillingPreparation->sizeHint());
    ui->confectioneryFieldList->setItemWidget(itemFillingPreparation,wgtFillingPreparation);
    preparationStaffing = true;
    ui->fillingPreparationBtn->setEnabled(false);
    } catch(QString e){
        m_decisionProcessing(e);
    }

}

void MainWindow::on_icingPreparationBtn_clicked()
{
    try{
    if(!GlazeUse){
        QString error = "Заливка не была выбрана!";
        qCritical(logError()) << error;
        throw error;
    }
    if(countGlazeOneThing == ""){
       QString error = "Количество заливки не было выбрано!";
       qCritical(logError()) << error;
       throw error;
    }
    if(!AmountUse){
       QString error = "Количество изделий, которые надо изготовить не было выбрано!";
       qCritical(logError()) << error;
       throw error;
    }
    QWidget* wgtIcingPreparation = new QWidget;
    QLabel* icingPreparationLbl = new QLabel("  "+ui->icingPreparationBtn->text()+" <<"+nameGlazeOneThing+">> на "+QString::number(countEx.toInt()*countGlazeOneThing.toInt())+" мл.");
    qInfo(logInfo()) << icingPreparationLbl->text();
    wFileMap.append(qMakePair(QString("icingPreparationLbl"), icingPreparationLbl->text()));
    QVBoxLayout *icingPreparationLt = new QVBoxLayout();
    icingPreparationLt->addWidget(icingPreparationLbl);

    QListWidgetItem* itemIcingPreparation = new QListWidgetItem( ui->confectioneryFieldList );
    wgtIcingPreparation->setLayout(icingPreparationLt);
    itemIcingPreparation->setSizeHint(wgtIcingPreparation->sizeHint());
    ui->confectioneryFieldList->setItemWidget(itemIcingPreparation,wgtIcingPreparation);
    preparationGlaze = true;
    ui->icingPreparationBtn->setEnabled(false);
    }catch(QString e){
        m_decisionProcessing(e);
    }
}

void MainWindow::on_powderPreparationBtn_clicked()
{
    try{
    if(!PowderUse){
        QString error = "Присыпка не была выбрана!";
        qCritical(logError()) << error;
        throw error;
    }
    if(countPowderOneThing == ""){
       QString error = "Количество присыпки не было выбрано!";
       qCritical(logError()) << error;
       throw error;
    }
    if(!AmountUse){
       QString error = "Колличество изделий, которые надо изготовить не было выбрано!";
       qCritical(logError()) << error;
       throw error;
    }
        QWidget* wgtPowderPreparation = new QWidget;
        QLabel* powderPreparationLbl = new QLabel("  "+ui->powderPreparationBtn->text()+" <<"+namePowderOneThing+">> на "+QString::number(countEx.toInt()*countPowderOneThing.toInt())+" гр.");
        qInfo(logInfo()) << powderPreparationLbl->text();
        QVBoxLayout *powderPreparationLt = new QVBoxLayout();
        powderPreparationLt->addWidget(powderPreparationLbl);
        wFileMap.append(qMakePair(QString("powderPreparationLbl"), powderPreparationLbl->text()));
        QListWidgetItem* itemPowderPreparation = new QListWidgetItem( ui->confectioneryFieldList );
        wgtPowderPreparation->setLayout(powderPreparationLt);
        itemPowderPreparation->setSizeHint(wgtPowderPreparation->sizeHint());
        ui->confectioneryFieldList->setItemWidget(itemPowderPreparation,wgtPowderPreparation);
        preparationPowder = true;
        ui->powderPreparationBtn->setEnabled(false);
    }catch(QString e){
        m_decisionProcessing(e);
    }

}

void MainWindow::on_productionCycleBtn_clicked()
{
    QWidget* wgtProductionCycle = new QWidget;
    QLabel* productionCycleLbl = new QLabel("   "+ui->productionCycleBtn->text()+" изделия <<"+trackerComboBox+">> от 1 до "+countEx+" штук:");
    qInfo(logInfo()) << productionCycleLbl->text();
    wFileMap.append(qMakePair(QString("productionCycleLbl"), productionCycleLbl->text()));
    QVBoxLayout *productionCycleLt = new QVBoxLayout();
    productionCycleLt->addWidget(productionCycleLbl);

    QListWidgetItem* itemProductionCycle = new QListWidgetItem( ui->confectioneryFieldList );
    wgtProductionCycle->setLayout(productionCycleLt);
    itemProductionCycle->setSizeHint(wgtProductionCycle->sizeHint());
    if(trackerComboBox == "Леденец"){
        ui->glossyCaramelBtn->setEnabled(true);
    }else if(trackerComboBox == "Шоколадные шарики"){
        ui->fillFrostingBtn->setEnabled(true);
        ui->formationSolidFillingBtn->setEnabled(true);
        ui->sprinkleProductBtn->setEnabled(true);
    }
    else{
        ui->doughDivisionBtn->setEnabled(true);
        ui->putDoughMoldBtn->setEnabled(true);
        ui->sendDoughOvenBtn->setEnabled(true);
        ui->takeDoughOvenBtn->setEnabled(true);
        ui->pourStaffingBtn->setEnabled(true);
        ui->drizzleGlazeDoughBtn->setEnabled(true);
        ui->sprinkleProductBtn->setEnabled(true);
    }
    ui->confectioneryFieldList->setItemWidget(itemProductionCycle,wgtProductionCycle);
    ui->endProductionCycleBtn->setEnabled(true);
    ui->packProductBtn->setEnabled(true);
    ui->productMarkingBtn->setEnabled(true);
    ui->sendingStorageBtn->setEnabled(true);
    ui->productionCycleBtn->setEnabled(false);
}

void MainWindow::on_endProductionCycleBtn_clicked()
{
    try{
    if(!sendingStorageUse){
        QString error = "Изделие не отправлено на хранение!";
        qCritical(logError()) << error;
        throw error;
    }
    QWidget* wgtEndProductionCycle = new QWidget;
    QLabel* endProductionCycleLbl = new QLabel("   "+ui->endProductionCycleBtn->text()+" изделия <<"+trackerComboBox+">> в размере "+countEx+" штук");
    qInfo(logInfo()) << endProductionCycleLbl->text();
    wFileMap.append(qMakePair(QString("endProductionCycleLbl"), endProductionCycleLbl->text()));
    QVBoxLayout *endProductionCycleLt = new QVBoxLayout();
    endProductionCycleLt->addWidget(endProductionCycleLbl);

    QListWidgetItem* itemEndProductionCycle = new QListWidgetItem( ui->confectioneryFieldList );
    wgtEndProductionCycle->setLayout(endProductionCycleLt);
    itemEndProductionCycle->setSizeHint(wgtEndProductionCycle->sizeHint());
    ui->confectioneryFieldList->setItemWidget(itemEndProductionCycle,wgtEndProductionCycle);
    ui->productionCycleBtn->setEnabled(true);
    ui->endProductionCycleBtn->setEnabled(false);
    ui->doughDivisionBtn->setEnabled(false);
    ui->putDoughMoldBtn->setEnabled(false);
    ui->sendDoughOvenBtn->setEnabled(false);
    ui->takeDoughOvenBtn->setEnabled(false);
    ui->pourStaffingBtn->setEnabled(false);
    ui->drizzleGlazeDoughBtn->setEnabled(false);
    ui->sprinkleProductBtn->setEnabled(false);
    ui->packProductBtn->setEnabled(false);
    ui->productMarkingBtn->setEnabled(false);
    ui->sendingStorageBtn->setEnabled(false);
     ui->glossyCaramelBtn->setEnabled(false);
     ui->fillFrostingBtn->setEnabled(false);
     ui->formationSolidFillingBtn->setEnabled(false);
     endProductionCycleUse = true;
     ui->endProductionCycleBtn->setEnabled(false);
    }catch(QString e){
        m_decisionProcessing(e);
    }
}

void MainWindow::on_doughDivisionBtn_clicked()
{
    try{
    if(!preparationDough){
        QString error = "Тесто не заготовлено!";
        qCritical(logError()) << error;
        throw error;
    }
    QWidget* wgtDoughDivision = new QWidget;
    QLabel* doughDivisionLbl = new QLabel("      Отрезать кусок теста изделия <<"+trackerComboBox+">> для 1 штуки");
    qInfo(logInfo()) << doughDivisionLbl->text();
    wFileMap.append(qMakePair(QString("doughDivisionLbl"), doughDivisionLbl->text()));
    QVBoxLayout *doughDivisionLt = new QVBoxLayout();
    doughDivisionLt->addWidget(doughDivisionLbl);

    QListWidgetItem* itemDoughDivision = new QListWidgetItem( ui->confectioneryFieldList );
    wgtDoughDivision->setLayout(doughDivisionLt);
    itemDoughDivision->setSizeHint(wgtDoughDivision->sizeHint());
    ui->confectioneryFieldList->setItemWidget(itemDoughDivision,wgtDoughDivision);
    dividingDough = true;
    ui->doughDivisionBtn->setEnabled(false);
    }catch(QString e){
        m_decisionProcessing(e);
    }

}

void MainWindow::on_putDoughMoldBtn_clicked()
{
    try{
    if(!dividingDough){
        QString error = "Тесто не поделено на куски!";
        qCritical(logError()) << error;
        throw error;
    }
    QWidget* wgtPutDoughMold = new QWidget;
    QLabel* prepareDoughMoldLbl = new QLabel("      Деление теста на куски предполагает выполнение следующих действий:\n      1. Подготовить форму для изделия <<"+trackerComboBox+">>");
    QLabel* putDoughMoldLbl = new QLabel("      2. Положить тесто изделия <<"+trackerComboBox+">> в форму");
    wFileMap.append(qMakePair(QString("prepareDoughMoldLbl"), prepareDoughMoldLbl->text()+"\n"+putDoughMoldLbl->text()));
    qInfo(logInfo()) << prepareDoughMoldLbl->text();
    qInfo(logInfo()) << putDoughMoldLbl->text();
    QVBoxLayout *putDoughMoldLt = new QVBoxLayout();
    putDoughMoldLt->addWidget(prepareDoughMoldLbl);
    putDoughMoldLt->addWidget(putDoughMoldLbl);

    QListWidgetItem* itemPutDoughMold = new QListWidgetItem( ui->confectioneryFieldList );
    wgtPutDoughMold->setLayout(putDoughMoldLt);
    itemPutDoughMold->setSizeHint(wgtPutDoughMold->sizeHint());
    ui->confectioneryFieldList->setItemWidget(itemPutDoughMold,wgtPutDoughMold);
    putDough = true;
    ui->putDoughMoldBtn->setEnabled(false);
    }catch(QString e){
        m_decisionProcessing(e);
    }
}

void MainWindow::on_sendDoughOvenBtn_clicked()
{
    try{
    if(!putDough){
        QString error = "Тесто не в формах!";
        qCritical(logError()) << error;
        throw error;
    }
    QWidget* wgtSendDoughOven = new QWidget;
    QLabel* sendDoughOvenLbl = new QLabel("      Отправить изделие <<"+trackerComboBox+">> в печь");
    wFileMap.append(qMakePair(QString("sendDoughOvenLbl"), sendDoughOvenLbl->text()));
    qInfo(logInfo()) << sendDoughOvenLbl->text();
    QVBoxLayout *sendDoughOvenLt = new QVBoxLayout();
    sendDoughOvenLt->addWidget(sendDoughOvenLbl);
    QListWidgetItem* itemSendDoughOven = new QListWidgetItem( ui->confectioneryFieldList );
    wgtSendDoughOven->setLayout(sendDoughOvenLt);
    itemSendDoughOven->setSizeHint(wgtSendDoughOven->sizeHint());
    ui->confectioneryFieldList->setItemWidget(itemSendDoughOven,wgtSendDoughOven);
    sendDough = true;
    ui->sendDoughOvenBtn->setEnabled(false);
    }catch(QString e){
        m_decisionProcessing(e);
    }
}

void MainWindow::on_takeDoughOvenBtn_clicked()
{
    try{
    if(!sendDough){
        QString error = "Тесто не отправлено!";
        qCritical(logError()) << error;
        throw error;
    }
    QWidget* wgtTakeDoughOven = new QWidget;
    QLabel* takeDoughOvenLbl = new QLabel("      Достать изделие <<"+trackerComboBox+">> из печи");
    wFileMap.append(qMakePair(QString("takeDoughOvenLbl"), takeDoughOvenLbl->text()));
    qInfo(logInfo()) << takeDoughOvenLbl->text();
    QVBoxLayout *takeDoughOvenLt = new QVBoxLayout();
    takeDoughOvenLt->addWidget(takeDoughOvenLbl);
    QListWidgetItem* itemTakeDoughOven = new QListWidgetItem( ui->confectioneryFieldList );
    wgtTakeDoughOven->setLayout(takeDoughOvenLt);
    itemTakeDoughOven->setSizeHint(wgtTakeDoughOven->sizeHint());
    ui->confectioneryFieldList->setItemWidget(itemTakeDoughOven,wgtTakeDoughOven);
    getDough = true;
    ui->takeDoughOvenBtn->setEnabled(false);
    }catch(QString e){
        m_decisionProcessing(e);
    }
}

void MainWindow::on_pourStaffingBtn_clicked()
{
    try{
    if(!preparationStaffing){
        QString error = "Начинка не была подготовлена!";
        qCritical(logError()) << error;
        throw error;
    }
    if(tracker == "baking"){
        if(!getDough){
            QString error = "Забыли достать тесто!";
            qCritical(logError()) << error;
            throw error;
        }
    }

    QWidget* wgtPourStaffing = new QWidget;
    QLabel* pourStaffingLbl = new QLabel("      Заливка начинки в готовое тесто предполагает выполнение следующих действий:\n      1. Залить начинку <<"+nameStaffingOneThing+">> в кондитерский шприц");
    QLabel* pourStaffingBekingLbl = new QLabel("      2. Залить начинку в изделие <<"+trackerComboBox+">>");
    wFileMap.append(qMakePair(QString("pourStaffingLbl"), pourStaffingLbl->text()+"\n"+pourStaffingBekingLbl->text()));
    qInfo(logInfo()) << pourStaffingLbl->text();
    qInfo(logInfo()) << pourStaffingBekingLbl->text();
    QVBoxLayout *pourStaffingLt = new QVBoxLayout();
    pourStaffingLt->addWidget(pourStaffingLbl);
    pourStaffingLt->addWidget(pourStaffingBekingLbl);
    QListWidgetItem* itemPourStaffing = new QListWidgetItem( ui->confectioneryFieldList );
    wgtPourStaffing->setLayout(pourStaffingLt);
    itemPourStaffing->setSizeHint(wgtPourStaffing->sizeHint());
    ui->confectioneryFieldList->setItemWidget(itemPourStaffing,wgtPourStaffing);
    ui->pourStaffingBtn->setEnabled(false);
    }catch(QString e){
        m_decisionProcessing(e);
    }
}

void MainWindow::on_drizzleGlazeDoughBtn_clicked()
{
    try{
    if(!preparationGlaze){
        QString error = "Глазурь не была подготовлена!";
        qCritical(logError()) << error;
        throw error;
    }
    if(tracker == "baking"){
        if(!getDough){
            QString error = "Забыли достать тесто!";
            qCritical(logError()) << error;
            throw error;
        }
    }
    QWidget* wgtDrizzleGlazeDough = new QWidget;
    QLabel* drizzleGlazeDoughLbl = new QLabel("      Залить глазурь <<"+nameGlazeOneThing+">> на изделие <<"+trackerComboBox+">>");
    wFileMap.append(qMakePair(QString("drizzleGlazeDoughLbl"), drizzleGlazeDoughLbl->text()));
    qInfo(logInfo()) << drizzleGlazeDoughLbl->text();
    QVBoxLayout *drizzleGlazeDoughLt = new QVBoxLayout();
    drizzleGlazeDoughLt->addWidget(drizzleGlazeDoughLbl);
    QListWidgetItem* itemDrizzleGlazeDough = new QListWidgetItem( ui->confectioneryFieldList );
    wgtDrizzleGlazeDough->setLayout(drizzleGlazeDoughLt);
    itemDrizzleGlazeDough->setSizeHint(wgtDrizzleGlazeDough->sizeHint());
    ui->confectioneryFieldList->setItemWidget(itemDrizzleGlazeDough,wgtDrizzleGlazeDough);
    ui->drizzleGlazeDoughBtn->setEnabled(false);
    }catch(QString e){
        m_decisionProcessing(e);
    }
}

void MainWindow::on_sprinkleProductBtn_clicked()
{
    try{
    if(!preparationPowder){
        QString error = "Присыпка не была подготовлена!";
        qCritical(logError()) << error;
        throw error;
    }
    if(tracker == "baking"){
        if(!getDough){
            QString error = "Забыли достать тесто!";
            qCritical(logError()) << error;
            throw error;
        }
    }
    if(tracker == "sweets"){
        if(!pourLazeSolidFillingUse){
            QString error = "Залейте глазурью твердую начинку!";
            qCritical(logError()) << error;
            throw error;
        }
    }

    QWidget* wgtSprinkleProduct = new QWidget;
    QLabel* sprinkleProductLbl = new QLabel("      Засыпать присыпку <<"+namePowderOneThing+">> на изделие <<"+trackerComboBox+">>");
    qInfo(logInfo()) << sprinkleProductLbl->text();
    wFileMap.append(qMakePair(QString("sprinkleProductLbl"), sprinkleProductLbl->text()));
    QVBoxLayout *sprinkleProductLt = new QVBoxLayout();
    sprinkleProductLt->addWidget(sprinkleProductLbl);
    QListWidgetItem* itemSprinkleProduct = new QListWidgetItem( ui->confectioneryFieldList );
    wgtSprinkleProduct->setLayout(sprinkleProductLt);
    itemSprinkleProduct->setSizeHint(wgtSprinkleProduct->sizeHint());
    ui->confectioneryFieldList->setItemWidget(itemSprinkleProduct,wgtSprinkleProduct);
    ui->sprinkleProductBtn->setEnabled(false);
    }catch(QString e){
        m_decisionProcessing(e);
    }
}

void MainWindow::on_packProductBtn_clicked()
{
    QWidget* wgtPackProduct = new QWidget;
    QLabel* packProductLbl = new QLabel("      Упаковать изделие <<"+trackerComboBox+">>");
    qInfo(logInfo()) << packProductLbl->text();
    wFileMap.append(qMakePair(QString("packProductLbl"), packProductLbl->text()));
    QVBoxLayout *packProductLt = new QVBoxLayout();
    if(trackerComboBox == "Леденец"){
        QLabel* packProductSweetLbl = new QLabel("      Разложить остывшую карамель по формочкам для изделия <<"+trackerComboBox+">>");
        wFileMap.append(qMakePair(QString("packProductSweetLbl"), packProductSweetLbl->text()));
        qInfo(logInfo()) << packProductSweetLbl->text();
        packProductLt->addWidget(packProductSweetLbl);
    }
    packProductLt->addWidget(packProductLbl);
    QListWidgetItem* itemPackProduct = new QListWidgetItem( ui->confectioneryFieldList );
    wgtPackProduct->setLayout(packProductLt);
    itemPackProduct->setSizeHint(wgtPackProduct->sizeHint());
    ui->confectioneryFieldList->setItemWidget(itemPackProduct,wgtPackProduct);
    packProductUse = true;
    ui->packProductBtn->setEnabled(false);
}

void MainWindow::on_productMarkingBtn_clicked()
{
    try{
    if(!packProductUse){
        QString error = "Изделие не упаковано!";
        qCritical(logError()) << error;
        throw error;
    }
    QWidget* wgtProductMarking = new QWidget;
    QLabel* productMarkingLbl = new QLabel("      Маркировать коробку изделием <<"+trackerComboBox+">>");
    wFileMap.append(qMakePair(QString("productMarkingLbl"), productMarkingLbl->text()));
    qInfo(logInfo()) << productMarkingLbl->text();
    QVBoxLayout *productMarkingLt = new QVBoxLayout();
    productMarkingLt->addWidget(productMarkingLbl);
    QListWidgetItem* itemProductMarking = new QListWidgetItem( ui->confectioneryFieldList );
    wgtProductMarking->setLayout(productMarkingLt);
    itemProductMarking->setSizeHint(wgtProductMarking->sizeHint());
    ui->confectioneryFieldList->setItemWidget(itemProductMarking,wgtProductMarking);
    productMarkingUse = true;
    ui->productMarkingBtn->setEnabled(false);
    }catch(QString e){
        m_decisionProcessing(e);
    }
}

void MainWindow::on_sendingStorageBtn_clicked()
{
    try{
    if(!productMarkingUse){
        QString error = "Изделие не промаркировано!";
        qCritical(logError()) << error;
        throw error;
    }
    QWidget* wgtSendingStorage = new QWidget;
    QLabel* sendingStorageLbl = new QLabel("      Отправка на хранение коробку с изделием <<"+trackerComboBox+">>");
    wFileMap.append(qMakePair(QString("sendingStorageLbl"), sendingStorageLbl->text()));
    qInfo(logInfo()) << sendingStorageLbl->text();
    QVBoxLayout *sendingStorageLt = new QVBoxLayout();
    sendingStorageLt->addWidget(sendingStorageLbl);
    QListWidgetItem* itemSendingStorage = new QListWidgetItem( ui->confectioneryFieldList );
    wgtSendingStorage->setLayout(sendingStorageLt);
    itemSendingStorage->setSizeHint(wgtSendingStorage->sizeHint());
    ui->confectioneryFieldList->setItemWidget(itemSendingStorage,wgtSendingStorage);
    sendingStorageUse = true;
    ui->sendingStorageBtn->setEnabled(false);
    }catch(QString e){
        m_decisionProcessing(e);
    }
}

void MainWindow::on_makingCaramelSyrupBtn_clicked()
{
    try{
    if(!SweetStuffing){
        QString error = "Ароматизатор не был выбран!";
        qCritical(logError()) << error;
        throw error;
    }
    if(!AmountUse){
       QString error = "Количество изделий, которые надо изготовить не было выбрано!";
       qCritical(logError()) << error;
       throw error;
    }
    QWidget* wgtMakingCaramelSyrup = new QWidget;
    QLabel* makingCaramelSyrupLbl = new QLabel("  Приготовление карамельного сиропа с <<"+nameStaffingOneThing+">> с ароматизатором в объеме "+QString::number(countEx.toInt()*countStaffingOneThing.toInt())+" миллилитра, для изделия <<"+trackerComboBox+">>");
    wFileMap.append(qMakePair(QString("makingCaramelSyrupLbl"), makingCaramelSyrupLbl->text()));
    qInfo(logInfo()) << makingCaramelSyrupLbl->text();
    QVBoxLayout *makingCaramelSyrupLt = new QVBoxLayout();
   makingCaramelSyrupLt->addWidget(makingCaramelSyrupLbl);
    QListWidgetItem* itemMakingCaramelSyrup = new QListWidgetItem( ui->confectioneryFieldList );
    wgtMakingCaramelSyrup->setLayout(makingCaramelSyrupLt);
    itemMakingCaramelSyrup->setSizeHint(wgtMakingCaramelSyrup->sizeHint());
    ui->confectioneryFieldList->setItemWidget(itemMakingCaramelSyrup,wgtMakingCaramelSyrup);
    preparationCaramelSyrupUse = true;
    ui->makingCaramelSyrupBtn->setEnabled(false);
    }catch(QString e){
        m_decisionProcessing(e);
    }
}

void MainWindow::on_preparationCaramelMassBtn_clicked()
{
    try{
    if(!preparationCaramelSyrupUse){
        QString error = "Подготовьте карамельный сироп!";
        qCritical(logError()) << error;
        throw error;
    }
    QWidget* wgtPreparationCaramelMass = new QWidget;
    QLabel* preparationCaramelMassLbl = new QLabel("  Заготовка карамельной массы изделия <<"+trackerComboBox+">>");
    wFileMap.append(qMakePair(QString("preparationCaramelMassLbl"), preparationCaramelMassLbl->text()));
    qInfo(logInfo()) << preparationCaramelMassLbl->text();
    QVBoxLayout *preparationCaramelMassLt = new QVBoxLayout();
    preparationCaramelMassLt->addWidget(preparationCaramelMassLbl);
    QListWidgetItem* itemPreparationCaramelMass = new QListWidgetItem( ui->confectioneryFieldList );
    wgtPreparationCaramelMass->setLayout(preparationCaramelMassLt);
    itemPreparationCaramelMass->setSizeHint(wgtPreparationCaramelMass->sizeHint());
    ui->confectioneryFieldList->setItemWidget(itemPreparationCaramelMass,wgtPreparationCaramelMass);
    preparationCaramelMassUse = true;
    ui->preparationCaramelMassBtn->setEnabled(false);
    }catch(QString e){
        m_decisionProcessing(e);
    }
}

void MainWindow::on_coolingCaramelMassBtn_clicked()
{
    try{
    if(!preparationCaramelMassUse){
        QString error = "Заготовьте карамельную массу!";
        qCritical(logError()) << error;
        throw error;
    }
    QWidget* wgtCoolingCaramelMass = new QWidget;
    QLabel* coolingCaramelMassLbl = new QLabel("  Охлаждение карамельной массы изделия <<"+trackerComboBox+">>");
    wFileMap.append(qMakePair(QString("coolingCaramelMassLbl"), coolingCaramelMassLbl->text()));
    qInfo(logInfo()) << coolingCaramelMassLbl->text();
    QVBoxLayout *coolingCaramelMassLt = new QVBoxLayout();
    coolingCaramelMassLt->addWidget(coolingCaramelMassLbl);
    QListWidgetItem* itemCoolingCaramelMass = new QListWidgetItem( ui->confectioneryFieldList );
    wgtCoolingCaramelMass->setLayout(coolingCaramelMassLt);
    itemCoolingCaramelMass->setSizeHint(wgtCoolingCaramelMass->sizeHint());
    ui->confectioneryFieldList->setItemWidget(itemCoolingCaramelMass,wgtCoolingCaramelMass);
    coolingCaramelMassUse = true;
    ui->coolingCaramelMassBtn->setEnabled(false);
    }catch(QString e){
        m_decisionProcessing(e);
    }
}

void MainWindow::on_promCaramelMassBtn_clicked()
{
    try{
    if(!coolingCaramelMassUse){
        QString error = "Охладите карамельную массу!";
        qCritical(logError()) << error;
        throw error;
    }
    QWidget* wgtPromCaramelMass = new QWidget;
    QLabel* promCaramelMassLbl = new QLabel("  Проминка карамельной массы изделия <<"+trackerComboBox+">>");
    wFileMap.append(qMakePair(QString("promCaramelMassLbl"), promCaramelMassLbl->text()));
    qInfo(logInfo()) << promCaramelMassLbl->text();
    QVBoxLayout *promCaramelMassLt = new QVBoxLayout();
    promCaramelMassLt->addWidget(promCaramelMassLbl);
    QListWidgetItem* itemPromCaramelMass = new QListWidgetItem( ui->confectioneryFieldList );
    wgtPromCaramelMass->setLayout(promCaramelMassLt);
    itemPromCaramelMass->setSizeHint(wgtPromCaramelMass->sizeHint());
    ui->confectioneryFieldList->setItemWidget(itemPromCaramelMass,wgtPromCaramelMass);
    caramelMassFillingUse = true;
    ui->promCaramelMassBtn->setEnabled(false);
    }catch(QString e){
        m_decisionProcessing(e);
    }
}

void MainWindow::on_shapingCaramelBtn_clicked()
{
    try{
    if(!caramelMassFillingUse){
        QString error = "Промните карамельную массу!";
        qCritical(logError()) << error;
        throw error;
    }
    QWidget* wgtShapingCaramel = new QWidget;
    QLabel* shapingCaramelLbl = new QLabel("  Формирование карамели в вальцевой машине изделия <<"+trackerComboBox+">>");
    wFileMap.append(qMakePair(QString("shapingCaramelLbl"), shapingCaramelLbl->text()));
    qInfo(logInfo()) << shapingCaramelLbl->text();
    QVBoxLayout *shapingCaramelLt = new QVBoxLayout();
    shapingCaramelLt->addWidget(shapingCaramelLbl);
    QListWidgetItem* itemShapingCaramel = new QListWidgetItem( ui->confectioneryFieldList );
    wgtShapingCaramel->setLayout(shapingCaramelLt);
    itemShapingCaramel->setSizeHint(wgtShapingCaramel->sizeHint());
    ui->confectioneryFieldList->setItemWidget(itemShapingCaramel,wgtShapingCaramel);
    formationCaramelUse = true;
    ui->shapingCaramelBtn->setEnabled(false);
    }catch(QString e){
        m_decisionProcessing(e);
    }
}

void MainWindow::on_coolingCaramelBtn_clicked()
{
    try{
    if(!formationCaramelUse){
        QString error = "Сформируйте карамель!";
        qCritical(logError()) << error;
        throw error;
    }
    QWidget* wgtCoolingCaramel = new QWidget;
    QLabel* coolingCaramelLbl = new QLabel("    Охлаждение карамели предполагает следующие инструкции:\n    1. Охлаждение карамели до температуры 35 °С изделия <<"+trackerComboBox+">>");
    QLabel* coolingCaramel1Lbl = new QLabel("    2. Влажность воздуха в цехе - не более 93%, температура - от 10 до 12 °С");
    wFileMap.append(qMakePair(QString("coolingCaramelLbl"), coolingCaramelLbl->text()+"\n"+coolingCaramel1Lbl->text()));
    qInfo(logInfo()) << coolingCaramelLbl->text();
    qInfo(logInfo()) << coolingCaramel1Lbl->text();
    QVBoxLayout *coolingCaramelLt = new QVBoxLayout();
    coolingCaramelLt->addWidget(coolingCaramelLbl);
    coolingCaramelLt->addWidget(coolingCaramel1Lbl);
    QListWidgetItem* itemCoolingCaramel = new QListWidgetItem( ui->confectioneryFieldList );
    wgtCoolingCaramel->setLayout(coolingCaramelLt);
    itemCoolingCaramel->setSizeHint(wgtCoolingCaramel->sizeHint());
    ui->confectioneryFieldList->setItemWidget(itemCoolingCaramel,wgtCoolingCaramel);
    caramelCoolingUse = true;
    ui->coolingCaramelBtn->setEnabled(false);
    }catch(QString e){
        m_decisionProcessing(e);
    }
}

void MainWindow::on_glossyCaramelBtn_clicked()
{
    try{
    if(!endGlossCreationUse){
        QString error = "Создайте глянец!";
        qCritical(logError()) << error;
        throw error;
    }
    if(!caramelCoolingUse){
        QString error = "Охладите карамель!";
        qCritical(logError()) << error;
        throw error;
    }
    QWidget* wgtGlossyCaramel = new QWidget;
    QLabel* glossyCaramelLbl = new QLabel("      Покрытие специальной жировой смесью - <<глянцем>> изделия <<"+trackerComboBox+">>");
    wFileMap.append(qMakePair(QString("glossyCaramelLbl"), glossyCaramelLbl->text()));
    qInfo(logInfo()) << glossyCaramelLbl->text();
    QVBoxLayout *glossyCaramelLt = new QVBoxLayout();
    glossyCaramelLt->addWidget(glossyCaramelLbl);
    QListWidgetItem* itemGlossyCaramel = new QListWidgetItem( ui->confectioneryFieldList );
    wgtGlossyCaramel->setLayout(glossyCaramelLt);
    itemGlossyCaramel->setSizeHint(wgtGlossyCaramel->sizeHint());
    ui->confectioneryFieldList->setItemWidget(itemGlossyCaramel,wgtGlossyCaramel);
    ui->glossyCaramelBtn->setEnabled(false);
    }catch(QString e){
        m_decisionProcessing(e);
    }
}

void MainWindow::on_formationSolidFillingBtn_clicked()
{
    try{
    if(!preparationStaffing){
        QString error = "Подготовьте начинку!";
        qCritical(logError()) << error;
        throw error;
    }
    QWidget* wgtFormationSolidFilling = new QWidget;
    QLabel* formationSolidFillingLbl = new QLabel("      "+ui->formationSolidFillingBtn->text()+" изделия <<"+trackerComboBox+">> и раскладывание ее по формам");
    wFileMap.append(qMakePair(QString("formationSolidFillingLbl"), formationSolidFillingLbl->text()));
    qInfo(logInfo()) << formationSolidFillingLbl->text();
    QVBoxLayout *formationSolidFillingLt = new QVBoxLayout();
    formationSolidFillingLt->addWidget(formationSolidFillingLbl);
    QListWidgetItem* itemFormationSolidFilling = new QListWidgetItem( ui->confectioneryFieldList );
    wgtFormationSolidFilling->setLayout(formationSolidFillingLt);
    itemFormationSolidFilling->setSizeHint(wgtFormationSolidFilling->sizeHint());
    ui->confectioneryFieldList->setItemWidget(itemFormationSolidFilling,wgtFormationSolidFilling);
    formationSolidFillingUse = true;
    ui->formationSolidFillingBtn->setEnabled(false);
    }catch(QString e){
        m_decisionProcessing(e);
    }
}

void MainWindow::on_fillFrostingBtn_clicked()
{
    try{
    if(!formationSolidFillingUse){
        QString error = "Сформируйте твердую начинку!";
        qCritical(logError()) << error;
        throw error;
    }
    if(!preparationGlaze){
        QString error = "Подготовьте заливку!";
        qCritical(logError()) << error;
        throw error;
    }
    QWidget* wgtFillFrosting = new QWidget;
    QLabel* fillFrostingLbl = new QLabel("      "+ui->fillFrostingBtn->text()+" изделия <<"+trackerComboBox+">>");
    wFileMap.append(qMakePair(QString("fillFrostingLbl"), fillFrostingLbl->text()));
    qInfo(logInfo()) << fillFrostingLbl->text();
    QVBoxLayout *fillFrostingLt = new QVBoxLayout();
   fillFrostingLt->addWidget(fillFrostingLbl);
    QListWidgetItem* itemFillFrosting = new QListWidgetItem( ui->confectioneryFieldList );
    wgtFillFrosting->setLayout(fillFrostingLt);
    itemFillFrosting->setSizeHint(wgtFillFrosting->sizeHint());
    ui->confectioneryFieldList->setItemWidget(itemFillFrosting,wgtFillFrosting);
    pourLazeSolidFillingUse = true;
    ui->fillFrostingBtn->setEnabled(false);
    }catch(QString e){
        m_decisionProcessing(e);
    }
}

void MainWindow::on_deleteAllMenu_triggered()
{
    ui->confectioneryFieldList->clear();
    ui->beginInstractionBtn->setEnabled(true);
    ui->sweetsBtn->setEnabled(false);
    ui->bakingBtn->setEnabled(false);
    ui->stuffingBtn->setEnabled(false);
    ui->powderBtn->setEnabled(false);
    ui->endInstractionBtn->setEnabled(false);
    ui->glazeBtn->setEnabled(false);
    ui->startProductionBtn->setEnabled(false);
    ui->endProductionBtn->setEnabled(false);
    ui->amountBtn->setEnabled(false);
    ui->doughPreparationBtn->setEnabled(false);
    ui->fillingPreparationBtn->setEnabled(false);
    ui->icingPreparationBtn->setEnabled(false);
    ui->powderPreparationBtn->setEnabled(false);
    ui->productionCycleBtn->setEnabled(false);
    ui->endProductionCycleBtn->setEnabled(false);
    ui->doughDivisionBtn->setEnabled(false);
    ui->putDoughMoldBtn->setEnabled(false);
    ui->sendDoughOvenBtn->setEnabled(false);
    ui->takeDoughOvenBtn->setEnabled(false);
    ui->pourStaffingBtn->setEnabled(false);
    ui->drizzleGlazeDoughBtn->setEnabled(false);
    ui->sprinkleProductBtn->setEnabled(false);
    ui->packProductBtn->setEnabled(false);
    ui->productMarkingBtn->setEnabled(false);
    ui->sendingStorageBtn->setEnabled(false);
    ui->coolingCaramelBtn->setEnabled(false);
    ui->coolingCaramelMassBtn->setEnabled(false);
    ui->glossyCaramelBtn->setEnabled(false);
    ui->makingCaramelSyrupBtn->setEnabled(false);
    ui->preparationCaramelMassBtn->setEnabled(false);
    ui->promCaramelMassBtn->setEnabled(false);
    ui->shapingCaramelBtn->setEnabled(false);
    ui->glossCreationBtn->setEnabled(false);
    ui->glossCreationEndBtn->setEnabled(false);

    ui->fillFrostingBtn->setEnabled(false);
    ui->formationSolidFillingBtn->setEnabled(false);
    StaffingUse = false;
    PowderUse = false;
    GlazeUse = false;
    AmountUse = false;
    preparationStaffing = false;
    preparationPowder = false;
    preparationGlaze = false;
    bakingUse = false;
    sweetUse = false;
    countEx = "";
    countStaffingOneThing = "";
    countGlazeOneThing = "";
    countPowderOneThing = "";
    countGlossCreation = "";
    countGlossCreation1 = "";
    SweetStuffing = false;
    endProductionCycleUse = false;
    endProductionProcessUse = false;

    preparationCaramelSyrupUse = false;
    preparationCaramelMassUse = false;
    coolingCaramelMassUse = false;
    caramelMassFillingUse = false;
    formationCaramelUse = false;
    caramelCoolingUse = false;
    beginningGlossCreationUse = false;
    endGlossCreationUse = false;

    formationSolidFillingUse = false;
    pourLazeSolidFillingUse = false;

    preparationDough = false;
    dividingDough = false;
    putDough = false;
    sendDough = false;
    getDough = false;
    productMarkingUse = false;
    packProductUse = false;
    sendingStorageUse = false;
    wFileMap.clear();
}

void MainWindow::on_runInstrMenu_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Сохранить"),"",
                                tr("Instr (*.instr)"));
    if(fileName != ""){
        QFile file(fileName);
        if(!file.open(QIODevice::WriteOnly)){
            QMessageBox::critical(this, tr("Error"), tr("Could not create file"));
            return;
        }

        QTextStream stream(&file);
        for(int i = 0; i < wFileMap.size();i++){

            if(wFileMap[i].first == QString("stuffingLbl")){
                wFileMap[i].second = wFileMap[i].second + " объем в миллитрах на одну единицу изделия " +countStaffingOneThing;
            }
            if(wFileMap[i].first == QString("powderLbl")){
                wFileMap[i].second = wFileMap[i].second + " вес в граммах на одну единицу изделия " +countPowderOneThing;
            }
            if(wFileMap[i].first == QString("glazeLbl")){
                wFileMap[i].second = wFileMap[i].second + " объем в миллитрах на одну единицу изделия " +countGlazeOneThing;
            }
            if(wFileMap[i].first == QString("amountLbl")){
                wFileMap[i].second = wFileMap[i].second + countEx;
            }
            if(wFileMap[i].first == QString("glossCreation0Lbl")){
                wFileMap[i].second = wFileMap[i].second + "\n"+"Расплавленные - Парафин: "+countGlossCreation+ " миллилитров на всю партию леденцов\nВоск: "
                        + countGlossCreation1 + " миллилитров на всю партию леденцов";
            }
            stream<< wFileMap[i].second <<endl;
        }
        on_deleteAllMenu_triggered();
        file.close();
    }
}

void MainWindow::m_decisionProcessing(QString e){
    QMessageBox msgBox;
    msgBox.setWindowTitle("ВНИМАНИЕ!");
    msgBox.setText(e);
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.exec();
}
