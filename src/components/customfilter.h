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

#ifndef CUSTOMFILTER_H
#define CUSTOMFILTER_H

// Qt
#include <QSortFilterProxyModel>
#include <QMap>

#include <QDebug>

class CustomFilter: public QSortFilterProxyModel {
    Q_OBJECT

    public:
        CustomFilter(QObject *parent = nullptr);
        ~CustomFilter() override;

        Qt::ItemFlags flags(const QModelIndex &index) const override;

    protected:
        bool filterAcceptsRow(int row, const QModelIndex &sourceParent) const override;

    private:

};

#endif // CUSTOMFILTER_H
