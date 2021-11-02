#pragma once


#include <QMainWindow>
#include <functional>
#include "mdef"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow (QWidget *parent = nullptr);
    ~MainWindow ();

    void setIntegral (const std::function<f64 (f64, f64)> integral);

private slots:
    void on_btnCalculate_released ();

private:
    Ui::MainWindow *ui;
    std::function<f64 (f64, f64)> m_integral;
    u16 m_threads{1};
    u64 m_steps{1'000'000};
};
