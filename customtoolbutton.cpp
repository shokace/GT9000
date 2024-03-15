#include "CustomToolButton.h"


CustomToolButton::CustomToolButton(QWidget *parent) : QToolButton(parent) {
    // Load the SVG icon
    QIcon svgIcon(":/path/to/your/icon.svg");
    setIcon(svgIcon);

    // Adjust the icon size based on your SVG and button size
    setIconSize(QSize(24, 24)); // Example size, adjust as needed
}

void CustomToolButton::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);

    // Draw the button text using the default style
    painter.drawText(rect(), Qt::AlignCenter, text());

    // Get the current size of the icon
    QSize iconSize = QSize(24,24); // This line gets the QSize object representing the icon size

    // Calculate the icon position: horizontally centered, and just above the bottom
    int iconPosX = (width() - iconSize.width()) / 2;
    int iconPosY = height() - iconSize.height() - 5; // 5 pixels above the bottom

    // Create a QRect for the icon based on its calculated position and size
    QRect iconRect(iconPosX, iconPosY, iconSize.width(), iconSize.height());

    // Draw the icon
    painter.drawPixmap(iconRect, icon().pixmap(iconSize));
}
