/*
 * This file is part of QtEmu project.
 * Copyright (C) 2006-2009 Urs Wolfer <uwolfer @ fwo.ch> and Ben Klopfenstein <benklop gmail com>
 * Copyright (C) 2017-2025 Sergio Carlavilla <sergio.carlavilla91 @ gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

// Local
#include "machineconfigaccel.h"

/**
 * @brief Accelerator configuration window
 * @param machine, machine to be configured
 * @param parent, parent widget
 *
 * In this window the user can select what accelerators want to use and
 * it's order
 */
MachineConfigAccel::MachineConfigAccel(Machine *machine,
                                       QWidget *parent) : QWidget(parent)
{
    bool enableFields = true;

    if (machine->getState() != Machine::Stopped) {
        enableFields = false;
    }

    this->m_machine = machine;

    m_acceleratorButtonGroup = new QButtonGroup(this);

    m_acceleratorLayout = new QVBoxLayout();
    m_acceleratorLayout->setAlignment(Qt::AlignTop);

    QString accelerator = machine->getAccelerator();
    QMapIterator<QString, QString> it(SystemUtils::getAccelerators());
    int i = 0;

    while (it.hasNext()) {
        it.next();
        QRadioButton* radioBtn = new QRadioButton(this);
        radioBtn->setText(it.value());
        radioBtn->setChecked(it.key() == accelerator);
        m_acceleratorButtonGroup->addButton(radioBtn, i++);
        m_acceleratorLayout->addWidget(radioBtn);
    }

    m_acceleratorPageWidget = new QWidget();
    m_acceleratorPageWidget->setEnabled(enableFields);
    m_acceleratorPageWidget->setLayout(m_acceleratorLayout);
    qDebug() << "MachineConfigAccel created";
}

MachineConfigAccel::~MachineConfigAccel()
{
    qDebug() << "MachineConfigAccel destroyed";
}

/**
 * @brief Save the accelerators
 *
 * Save the selected accelerators in the specified order
 */
void MachineConfigAccel::saveAccelData()
{
    if (this->m_acceleratorButtonGroup->checkedId() == -1) {
        this->m_machine->setAccelerator("");
        return;
    }
    QList<QString> keys = SystemUtils::getAccelerators().keys();
    this->m_machine->setAccelerator(keys.at(this->m_acceleratorButtonGroup->checkedId()));
}
