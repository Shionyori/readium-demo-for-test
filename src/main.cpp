#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>
#include <QWidget>
#include <memory>
// Poppler Qt6 头文件
#include <poppler/qt6/poppler-qt6.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Poppler-Qt6 Demo");
    window.resize(800, 600);

    QLabel *label = new QLabel(&window);
    label->setAlignment(Qt::AlignCenter);
    label->setScaledContents(true);

    // 加载 PDF（放在可执行文件同级目录）
    std::unique_ptr<Poppler::Document> doc = Poppler::Document::load("sample.pdf");
    if (!doc || doc->isLocked()) {
        label->setText("无法打开 sample.pdf");
    } else {
        std::unique_ptr<Poppler::Page> page = doc->page(0); // 第一页
        if (page) {
            QImage img = page->renderToImage(150.0, 150.0); // 150 DPI
            if (!img.isNull()) {
                label->setPixmap(QPixmap::fromImage(img));
            } else {
                label->setText("渲染失败");
            }
        } else {
            label->setText("PDF 无第 1 页");
        }
    }

    QVBoxLayout *layout = new QVBoxLayout(&window);
    layout->addWidget(label);
    window.setLayout(layout);
    window.show();

    return app.exec();
}
