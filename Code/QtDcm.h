#ifndef QTDCM_H
#define QTDCM_H

#include "ui_qtdcm.h"
#include <QtGui>

class QtDcmPrivate;
class QtDcmManager;

/**
 * This class contains the widget for managing Dicom data. It is possible to read and display in a QTreeWidget
 * the content of a DICOMDIR. It is also possible to query and retrieve data from a PACS.
 * Once read/retrieve, each serie can be reconstructed, using the QtDcmManager.
 */
class QtDCM : public QLabel, public Ui::QtDCM
{
    Q_OBJECT
    public:
        QtDCM(QWidget *parent = 0); /** Classic constructor */
        ~QtDCM();
        /**
         * Get the pointer of the treewidget
         *
         * @return the pointer on the QTreeWidget
         */
//        QTreeView *
//        getTreeView()
//        {
//            return treeWidget;
//        }

        enum mode {CD, PACS};

        /**
         * Get the pointer of the QtDcm manager
         *
         * @return Pointer on QtDcmManager
         */
        QtDcmManager *
        getManager();

        /**
         * Clear the content of the QTreeWidget
         */
        void
        clearDisplay();

        /**
         * Display in the QTreeWidget the content of the list of patients from the manager
         *
         */
        void
        displayDicomdir();

        /**
         * Initialize SIGNAL/SLOTS connections of the different widget
         *
         */
        void
        initConnections();

        /**
         * Get the images filenames list of the current serie
         *
         */
        QList<QString>
        getImagesList();

        void
        exportToDirectory(QString directory);

    public slots:

        void
        sendEcho();

        void
        findSCU();

        /**
         * Slot called when dateComboBox is changed. This slots change the display parameters of the 2 date buttons
         *
         */
        void
        updateDateButtons(int index);

        /**
         * Slot that change the modality parameter of the query
         *
         */
        void
        updateModality(int index);

        void
        updateSex(int index);

        /**
         * Slot that launch the Date selection dialog. This change the begin date (or current date) for the Dicom query
         *
         */
        void
        startDateChanged(QDate date);

        /**
         * Slot that launch the Date selection dialog. This change the end date for the Dicom query (Use only in range mode)
         *
         */
        void
        endDateChanged(QDate date);

        /**
         * Slot called when a selected is made on the QTreeWidget. If a serie is selected, corresponding images filenames
         * are copied in _imagesList
         *
         */
        void
        itemSelected(QTreeWidgetItem* current, QTreeWidgetItem* previous);

        void
        itemClicked(QTreeWidgetItem* current, int);

//        void
//        patientItemClicked(QTreeWidgetItem* current, int);

        void
        patientItemSelected(QTreeWidgetItem* current, QTreeWidgetItem* previous);

        void
        studyItemSelected(QTreeWidgetItem* current, QTreeWidgetItem* previous);

        void
        serieItemSelected(QTreeWidgetItem* current, QTreeWidgetItem* previous);

        /**
         * Slot called when right clicking on the QTreeWidget. User can export or open a dicomdir from the context menu
         *
         */
        void
        contextExportMenu(const QPoint point);

        /**
         * Slot that launch a QFileDialog for choosing an output directory
         * where the current serie will be exported with dcm2nii (This is done by the _manager).
         *
         */
        void
        exportList();

        /**
         * Slot that query the list of server with the user specified parameters
         */
        void
        queryPACS();

        /**
         * Slot that launch a QFileDialog for choosing a dicomdir
         *
         *
         */
        void
        openDicomdir();

        /**
         * Slot that launch the PACS preferences dialog
         *
         */
        void
        editPreferences();

        /**
         * Slot called when user modify patient name edit line
         */
        void
        patientNameTextChanged(QString);

        /**
         * Slot called when user modify serie description edit line
         */
        void
        serieDescriptionTextChanged(QString);

        /**
         * Slot called when user modify study description edit line
         */
        void
        studyDescriptionTextChanged(QString);

        void
        showPreview();

    signals:
        void
        serieChecked(bool checked);
        void
        serieSelected(bool selected);

    private:
        QtDcmPrivate *d;
};

#endif

