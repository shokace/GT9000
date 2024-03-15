#ifndef CUSTOMTOOLBUTTON_H
#define CUSTOMTOOLBUTTON_H
#include <QToolButton>
#include <QPainter>
#include <QIcon>

class CustomToolButton : public QToolButton {
    Q_OBJECT

public:
    explicit CustomToolButton(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
};
#endif // CUSTOMTOOLBUTTON_H
