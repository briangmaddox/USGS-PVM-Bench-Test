/****************************************************************************
** PVMServerBenchmarkInputDialog meta object code from reading C++ file 'PVMServerBenchmarkInputDialog.h'
**
** Created: Thu Jul 26 13:37:00 2001
**      by: The Qt MOC ($Id: moc_PVMServerBenchmarkInputDialog.cpp,v 1.1.1.1 2001-10-09 16:31:21 cbilder Exp $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "PVMServerBenchmarkInputDialog.h"
#include <qmetaobject.h>
#include <qapplication.h>



const char *PVMServerBenchmarkInputDialog::className() const
{
    return "PVMServerBenchmarkInputDialog";
}

QMetaObject *PVMServerBenchmarkInputDialog::metaObj = 0;

void PVMServerBenchmarkInputDialog::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(PVMServerBenchmark::className(), "PVMServerBenchmark") != 0 )
	badSuperclassWarning("PVMServerBenchmarkInputDialog","PVMServerBenchmark");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString PVMServerBenchmarkInputDialog::tr(const char* s)
{
    return qApp->translate( "PVMServerBenchmarkInputDialog", s, 0 );
}

QString PVMServerBenchmarkInputDialog::tr(const char* s, const char * c)
{
    return qApp->translate( "PVMServerBenchmarkInputDialog", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* PVMServerBenchmarkInputDialog::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) PVMServerBenchmark::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void (PVMServerBenchmarkInputDialog::*m1_t0)();
    typedef void (QObject::*om1_t0)();
    typedef void (PVMServerBenchmarkInputDialog::*m1_t1)();
    typedef void (QObject::*om1_t1)();
    m1_t0 v1_0 = &PVMServerBenchmarkInputDialog::add_host_clicked;
    om1_t0 ov1_0 = (om1_t0)v1_0;
    m1_t1 v1_1 = &PVMServerBenchmarkInputDialog::rem_host_clicked;
    om1_t1 ov1_1 = (om1_t1)v1_1;
    QMetaData *slot_tbl = QMetaObject::new_metadata(2);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(2);
    slot_tbl[0].name = "add_host_clicked()";
    slot_tbl[0].ptr = (QMember)ov1_0;
    slot_tbl_access[0] = QMetaData::Public;
    slot_tbl[1].name = "rem_host_clicked()";
    slot_tbl[1].ptr = (QMember)ov1_1;
    slot_tbl_access[1] = QMetaData::Public;
    metaObj = QMetaObject::new_metaobject(
	"PVMServerBenchmarkInputDialog", "PVMServerBenchmark",
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    metaObj->set_slot_access( slot_tbl_access );
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    return metaObj;
}
