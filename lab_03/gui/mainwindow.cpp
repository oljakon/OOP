#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <QDesktopWidget>
#include <QFileDialog>
#include <QMessageBox>

#include "commands/command.hpp"
#include "drawer.hpp"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->frame->setFixedWidth(250);
    this->set_up_scene_view();
    ui->cameraChoiceButton->addItem(QString::number(0) + " : camera");
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent* e) {
    ssize_t model_current_index = ui->modelChoiceButton->currentIndex() - 1;
    size_t camera_current_index = ui->cameraChoiceButton->currentIndex();

    try {

        if (e->key() == Qt::Key_W) {
            commands::rotate_model_OX comm(ANGLE, model_current_index);
            this->command_controller.execute_command(comm);

        } else if (e->key() == Qt::Key_A) {
            commands::rotate_model_OY comm(ANGLE, model_current_index);
            this->command_controller.execute_command(comm);

        } else if (e->key() == Qt::Key_S) {
            commands::rotate_model_OX comm(-ANGLE, model_current_index);
            this->command_controller.execute_command(comm);

        } else if (e->key() == Qt::Key_D) {
            commands::rotate_model_OY comm(-ANGLE, model_current_index);
            this->command_controller.execute_command(comm);

        } else if (e->key() == Qt::Key_Z) {
            commands::rotate_model_OZ comm(-ANGLE, model_current_index);
            this->command_controller.execute_command(comm);

        } else if (e->key() == Qt::Key_X) {
            commands::rotate_model_OZ comm(ANGLE, model_current_index);
            this->command_controller.execute_command(comm);

        } else if (e->key() == Qt::Key_I) {
            point3d<double> point(0, OFFSET, 0);
            commands::move comm(point, model_current_index);
            this->command_controller.execute_command(comm);

        } else if (e->key() == Qt::Key_J) {
            point3d<double> point(-OFFSET, 0, 0);
            commands::move comm(point, model_current_index);
            this->command_controller.execute_command(comm);

        } else if (e->key() == Qt::Key_K) {
            point3d<double> point(0, -OFFSET, 0);
            commands::move comm(point, model_current_index);
            this->command_controller.execute_command(comm);

        } else if (e->key() == Qt::Key_L) {
            point3d<double> point(OFFSET, 0, 0);
            commands::move comm(point, model_current_index);
            this->command_controller.execute_command(comm);

        } else if (e->key() == Qt::Key_M) {
            point3d<double> point(0, 0, OFFSET);
            commands::move comm(point, model_current_index);
            this->command_controller.execute_command(comm);

        }  else if (e->key() == Qt::Key_N) {
            point3d<double> point(0, 0, -OFFSET);
            commands::move comm(point, model_current_index);
            this->command_controller.execute_command(comm);

        }  else if (e->key() == Qt::Key_Plus) {
            commands::scale comm(SCALE_FACTOR, model_current_index);
            this->command_controller.execute_command(comm);

        } else if (e->key() == Qt::Key_Minus) {
            commands::scale comm(1 / SCALE_FACTOR, model_current_index);
            this->command_controller.execute_command(comm);

        } else if (e->key() == Qt::Key_H) {
            commands::yaw comm(ANGLE, camera_current_index);
            this->command_controller.execute_command(comm);

        } else if (e->key() == Qt::Key_F) {
            commands::yaw comm(-ANGLE, camera_current_index);
            this->command_controller.execute_command(comm);

        } else if (e->key() == Qt::Key_T) {
            commands::pitch comm(-ANGLE, camera_current_index);
            this->command_controller.execute_command(comm);

        } else if (e->key() == Qt::Key_G) {
            commands::pitch comm(ANGLE, camera_current_index);
            this->command_controller.execute_command(comm);

        } else if (e->key() == Qt::Key_B) {
            commands::roll comm(-ANGLE, camera_current_index);
            this->command_controller.execute_command(comm);

        } else if (e->key() == Qt::Key_V) {
            commands::roll comm(ANGLE, camera_current_index);
            this->command_controller.execute_command(comm);
        }

        this->update_scene_view(camera_current_index);

    } catch (base_exception& ex) {
        QMessageBox::warning(this, "Error message", QString(ex.what()));
    }
}

void MainWindow::set_up_scene_view() {
    this->scene_view_scene = new QGraphicsScene(ui->sceneView);
    ui->sceneView->setMinimumSize(600, 600);
    ui->sceneView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->sceneView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->sceneView->installEventFilter(this);
}

void MainWindow::update_scene_view(ssize_t camera_index) {
    this->scene_view_scene->clear();
    drawer dr(this->scene_view_scene);
    commands::draw comm(dr, camera_index);
    this->command_controller.execute_command(comm);
    ui->sceneView->setScene(this->scene_view_scene);
}

void MainWindow::on_actionupload_model_triggered() {
    try {
        QString file_path = QFileDialog::getOpenFileName(this, QObject::tr("Specify file with model"),
                                                         QDir::currentPath(), QObject::tr("json (*.json)"));
        commands::upload_view comm(file_path.toStdString());
        this->command_controller.execute_command(comm);
        ui->listWidget->addItem(file_path.section("/", -1, -1).section(".", 0, 0));

    } catch (base_exception& ex) {
        QMessageBox::warning(this, "Error message", QString(ex.what()));
    }
}

void MainWindow::on_addSceneObjectButton_clicked() {
    try {

        if (ui->modelButton->isChecked() && ui->listWidget->count() > 0) {
            commands::add_model comm(ui->listWidget->currentIndex().row());
            this->command_controller.execute_command(comm);
            ui->modelChoiceButton->addItem(QString::number(ui->modelChoiceButton->count() - 1) + " : model");

        } else if (ui->cameraButton->isChecked()) {
            commands::add_camera comm;
            this->command_controller.execute_command(comm);
            ui->cameraChoiceButton->addItem(QString::number(ui->cameraChoiceButton->count()) + " : camera");
        }

        this->update_scene_view(ui->cameraChoiceButton->currentIndex());

    } catch (base_exception& ex) {
        QMessageBox::warning(this, "Error message", QString(ex.what()));
    }
}

void MainWindow::on_removeSceneObjectButton_clicked() {
    try {

        if (ui->modelButton->isChecked() && ui->modelChoiceButton->currentIndex() > 0) {
            commands::remove_model comm(ui->modelChoiceButton->currentIndex() - 1);
            this->command_controller.execute_command(comm);
            size_t i = static_cast<size_t>(ui->modelChoiceButton->currentIndex());
            ui->modelChoiceButton->removeItem(ui->modelChoiceButton->currentIndex());

            for (; i < static_cast<size_t>(ui->modelChoiceButton->count()); ++i) {
                ui->modelChoiceButton->setItemText(i, QString::number(i - 1) + " : model");
            }

        } else if (ui->cameraButton->isChecked() && ui->cameraChoiceButton->currentIndex() > 0) {
            commands::remove_camera comm(ui->cameraChoiceButton->currentIndex());
            this->command_controller.execute_command(comm);
            size_t i = static_cast<size_t>(ui->cameraChoiceButton->currentIndex());
            ui->cameraChoiceButton->removeItem(ui->cameraChoiceButton->currentIndex());

            for (; i < static_cast<size_t>(ui->cameraChoiceButton->count()); ++i) {
                ui->cameraChoiceButton->setItemText(i, QString::number(i) + " : camera");
            }
        }

        this->update_scene_view(ui->cameraChoiceButton->currentIndex());

    } catch (base_exception& ex) {
        QMessageBox::warning(this, "Error message", QString(ex.what()));
    }
}

void MainWindow::on_deleteViewButton_clicked() {
    try {
        commands::delete_view comm(ui->listWidget->currentIndex().row());
        this->command_controller.execute_command(comm);

    } catch (base_exception& ex) {
        QMessageBox::warning(this, "Error message", QString(ex.what()));
    }

    delete ui->listWidget->item(ui->listWidget->currentIndex().row());
}
