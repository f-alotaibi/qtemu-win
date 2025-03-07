/*
 * This file is part of QtEmu project.
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
#include "importdetailspage.h"

ImportDetailsPage::ImportDetailsPage(Machine *machine,
                                     QWidget *parent) : QWizardPage(parent)
{
    this->setTitle(tr("Machine details"));

    this->m_machine = machine;

    m_machineDescLabel = new QLabel(tr("Name") + ":", this);
    m_OSTypeDescLabel = new QLabel(tr("Operating system") + ":", this);
    m_OSVersionDescLabel = new QLabel(tr("Operating system version") + ":", this);
    m_processorDescLabel = new QLabel(tr("Processor") + ":", this);
    m_graphicsDescLabel = new QLabel(tr("Graphics") + ":", this);
    m_audioDescLabel = new QLabel(tr("Audio") + ":", this);
    m_RAMDescLabel = new QLabel(tr("RAM") + ":", this);
    m_acceleratorDescLabel = new QLabel(tr("Accelerator") + ":", this);

    m_machineNameLabel = new QLabel(this);
    m_machineNameLabel->setWordWrap(true);
    m_OSTypeLabel      = new QLabel(this);
    m_OSVersionLabel   = new QLabel(this);
    m_processorLabel   = new QLabel(this);
    m_graphicsLabel    = new QLabel(this);
    m_audioLabel       = new QLabel(this);
    m_audioLabel->setWordWrap(true);
    m_RAMLabel         = new QLabel(this);
    m_acceleratorLabel = new QLabel(this);
    m_acceleratorLabel->setWordWrap(true);

    m_mainLayout = new QGridLayout();
    m_mainLayout->addWidget(m_machineDescLabel,     0, 0, 1, 1);
    m_mainLayout->addWidget(m_machineNameLabel,     0, 1, 1, 1);
    m_mainLayout->addWidget(m_OSTypeDescLabel,      1, 0, 1, 1);
    m_mainLayout->addWidget(m_OSTypeLabel,          1, 1, 1, 1);
    m_mainLayout->addWidget(m_OSVersionDescLabel,   2, 0, 1, 1);
    m_mainLayout->addWidget(m_OSVersionLabel,       2, 1, 1, 1);
    m_mainLayout->addWidget(m_processorDescLabel,   3, 0, 1, 1);
    m_mainLayout->addWidget(m_processorLabel,       3, 1, 1, 1);
    m_mainLayout->addWidget(m_graphicsDescLabel,    4, 0, 1, 1);
    m_mainLayout->addWidget(m_graphicsLabel,        4, 1, 1, 1);
    m_mainLayout->addWidget(m_audioDescLabel,       5, 0, 1, 1);
    m_mainLayout->addWidget(m_audioLabel,           5, 1, 1, 3);
    m_mainLayout->addWidget(m_RAMDescLabel,         6, 0, 1, 1);
    m_mainLayout->addWidget(m_RAMLabel,             6, 1, 1, 1);
    m_mainLayout->addWidget(m_acceleratorDescLabel, 7, 0, 1, 1);
    m_mainLayout->addWidget(m_acceleratorLabel,     7, 1, 1, 1);

    this->setLayout(m_mainLayout);

    qDebug() << "ImportDetailsPage created";
}

ImportDetailsPage::~ImportDetailsPage()
{
    qDebug() << "ImportDetailsPage destroyed";
}

void ImportDetailsPage::initializePage()
{
    QString machineConfigFile = field("configFilePath").toString();
    QString machineDestinationPath = field("machineDestinationPath").toString();

    QJsonObject machineJSON = MachineUtils::readMachineFile(machineConfigFile);

    if (machineJSON.isEmpty()) {
        // TODO: Show message

        return;
    }

    MachineUtils::fillMachineObject(this->m_machine,
                                    machineJSON,
                                    "");

    m_machineNameLabel->setText(this->m_machine->getName());
    m_OSTypeLabel->setText(this->m_machine->getOSType());
    m_OSVersionLabel->setText(this->m_machine->getOSVersion());
    m_processorLabel->setText(this->m_machine->getCPUType());
    m_graphicsLabel->setText(this->m_machine->getGPUType());
    m_audioLabel->setText(QString::number(this->m_machine->getRAM()).append(" MiB"));
    m_RAMLabel->setText(this->m_machine->getAudioLabel());
    m_acceleratorLabel->setText(this->m_machine->getAccelerator());
}
