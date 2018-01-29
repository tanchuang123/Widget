#ifndef TTKMARQUEEWINDOW_H
#define TTKMARQUEEWINDOW_H

/* =================================================
 * This file is part of the TTK WidgetTools project
 * Copyright (C) 2015 - 2018 Greedysky Studio

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; If not, see <http://www.gnu.org/licenses/>.
 ================================================= */

#include <QMainWindow>
#include <QFrame>

namespace Ui {
class TTKMarqueeWindow;
}

class TTKMarqueeWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit TTKMarqueeWindow(QWidget *parent = 0);
    ~TTKMarqueeWindow();
    void setBackgroundColor(const QColor &color);

private slots:
    void sl_base();
    void selectColor();
private:
    Ui::TTKMarqueeWindow *ui;
    QFrame *ctrlFrame;  //颜色选择面板
    QFrame *contentFrame;   //具体显示面板
    bool                    useThemeColors;
    QColor                  foregroundColor;
    QColor                  backgroundColor;

};

#endif // TTKMARQUEEWINDOW_H
