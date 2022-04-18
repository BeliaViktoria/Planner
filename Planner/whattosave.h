#ifndef WHATTOSAVE_H
#define WHATTOSAVE_H

#include <QWidget>

namespace Ui {
class WhatToSave;
}

class WhatToSave : public QWidget
{
    Q_OBJECT

public:
    explicit WhatToSave(QWidget *parent = nullptr);
    ~WhatToSave();

private:
    Ui::WhatToSave *ui;
};

#endif // WHATTOSAVE_H
