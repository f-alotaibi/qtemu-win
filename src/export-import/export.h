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

#ifndef EXPORT_H
#define EXPORT_H

// Qt
#include <QWizard>

#include <QDebug>

// Local
#include "../machine.h"
#include "exportgeneralpage.h"
#include "exportdetailspage.h"
#include "exportmediapage.h"

class ExportWizard : public QWizard {
    Q_OBJECT

    public:
        explicit ExportWizard(Machine *machine,
                              QWidget *parent = nullptr);
        ~ExportWizard();

        enum { Page_General, Page_Details, Page_Media };

    signals:

    public slots:

    protected:

    private:

};

#endif // EXPORT_H
