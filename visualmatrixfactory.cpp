#include "visualmatrixfactory.h"
#include "flowmatrix.h"

#include <QMessageBox>

VisualProperties VisualMatrixFactory::properties() const
{
    VisualProperties properties;
    properties.name = tr("Flow Matrix Plugin");
    properties.shortName = "matrix";
    return properties;
}

Visual *VisualMatrixFactory::create(QWidget *parent)
{
    return new FlowMatrix(parent);
}

#if (QMMP_VERSION_INT < 0x10700) || (0x20000 <= QMMP_VERSION_INT && QMMP_VERSION_INT < 0x20200)
QDialog *VisualMatrixFactory::createConfigDialog(QWidget *parent)
#else
QDialog *VisualMatrixFactory::createSettings(QWidget *parent)
#endif
{
    Q_UNUSED(parent);
    return nullptr;
}

void VisualMatrixFactory::showAbout(QWidget *parent)
{
    QMessageBox::about(parent, tr("About Matrix Visual Plugin"),
                       tr("Qmmp Matrix Visual Plugin") + "\n" +
                       tr("Written by: Greedysky <greedysky@163.com>"));
}

QString VisualMatrixFactory::translation() const
{
    return QString();
}

#if QT_VERSION < QT_VERSION_CHECK(5,0,0)
#include <QtPlugin>
Q_EXPORT_PLUGIN2(matrix, VisualMatrixFactory)
#endif
