#ifndef MAINTP1_H
#define MAINTP1_H

#include <QMainWindow>
#include <QByteArray>
#include <QString>
#include <cstdint>

QT_BEGIN_NAMESPACE
namespace Ui { class Maintp1; }
QT_END_NAMESPACE

class Maintp1 : public QMainWindow
{
    Q_OBJECT

public:
    Maintp1(QWidget *parent = nullptr);
    ~Maintp1();

private slots:
    void onConnect();
    void onDisconnect();
    void onSelectCard();
    void onUpdate();
    void onPay();
    void onCharge();

private:
    void updateButtons();
    void closeReader();
    void showError(const QString &message);
    void feedback(bool success);
    bool checkStatus(int16_t status, const QString &action, bool show = true);
    bool checkCard();
    bool readIdentity(QString &nom, QString &prenom, bool show = true);
    bool readWallet(quint32 &balance, quint32 &backup, bool show = true);
    bool initializeWallet(quint32 value);
    void showWallet();
    void changeBalance(quint32 amount, bool credit);

    bool connected_ = false;
    bool cardSelected_ = false;
    QByteArray cardUid_;

    Ui::Maintp1 *ui;
};

#endif // MAINTP1_H