/* This file is part of qjson
 *
 * Copyright (C) 2009 Frank Osterfeld <osterfeld@kde.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef SERIALIZERRUNNABLE_H
#define SERIALIZERRUNNABLE_H

#include "qtjson_global.h"

namespace QJson {
  /**
  * @brief Convenience class for converting JSON data to QVariant objects using a dedicated thread
  */
  class QTJSON_EXPORT SerializerRunnable  : public QObject, public QRunnable
  {
    Q_OBJECT
    public:
      /**
      * This signal is emitted when the conversion process has been completed
      * @param data contains the JSON data that has to be converted
      * @param parent parent of the object
      **/
      explicit SerializerRunnable(QObject* parent = 0);
      ~SerializerRunnable();

      /**
       * Sets the json object to serialize.
       *
       * @param json QVariant containing the json representation to be serialized
       */
      void setJsonObject( const QVariant& json );

      /* reimp */ void run();

    Q_SIGNALS:
      /**
      * This signal is emitted when the serialization process has been completed
      * @param serialized contains the result of the serialization
      * @param ok if a serialization error occurs ok is set to false, otherwise it's set to true.
      * @param error_msg contains a string explaining the failure reason
      **/
      void parsingFinished(const QByteArray& serialized, bool ok, const QString& error_msg);

    private:
      Q_DISABLE_COPY(SerializerRunnable)
      class Private;
      Private* const d;
  };
}

#endif // SERIALIZERRUNNABLE_H
