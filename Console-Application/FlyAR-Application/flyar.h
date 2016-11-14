#ifndef FLYAR_H
#define FLYAR_H

#include <QWidget>
#include <QtWidgets>
#include <QColor>
#include <QImage>
#include <QPoint>
#include <QFile>
#include <QTextStream>

class FlyAR : public QWidget
{
    Q_OBJECT
public:
    FlyAR(QWidget *parent = 0);

    bool openImage(const QString &fileName);
    bool saveImage(const QString &fileName, const char *fileFormat);
    void setPenColor(const QColor &newColor);
    void setPenWidth(int newWidth);
    void setNewHeight(int newHeight);

    bool isModified() const { return modified; }
    QColor penColor() const { return myPenColor; }
    int penWidth() const { return myPenWidth; }

public slots:
    void clearImage();

protected:
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;

private:
    void drawLineTo(const QPoint &endPoint);
    void resizeImage(QImage *image, const QSize &newSize);
    void writeToFile(QString objectInfo);

    bool modified;
    bool scribbling;
    int myPenWidth;
    int objHeight;
    int objType;
    float xRadius;
    float yRadius;
    QColor myPenColor;
    QImage image;
    QPoint lastPoint;
    QString outFileName;
    QFile outFile;
    QString output;
};

#endif // FLYAR_H
