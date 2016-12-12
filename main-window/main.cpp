#include<cstdlib>

#include<QApplication>
#include<QCommandLineParser>
#include<KAboutData>
#include<KLocalizedString>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	KLocalizedString::setApplicationDomain("tutorial1");

	KAboutData aboutData(
			QStringLiteral("tutorial2"),
			i18n("Tutorial2"),
			QStringLiteral("1.0"),
			i18n("A simple Text area"),
			KAboutLicense::GPL,
			i18n("(c) 2016"),
			i18n("An info"),
			QStringLiteral("http://rudranilbasu.github.io/"),
			QStringLiteral("notMe@RNB.com")
			);
	aboutData.addAuthor(i18n("Rudra"), i18n("ThePhenomenalOne"), i18n("rudranilbasu.github.io"),QStringLiteral("huehuehue"));
	KAboutData::setApplicationData(aboutData);

	QCommandLineParser parser;
	parser.addHelpOption();
	parser.addVersionOption();
	aboutData.setupCommandLine(&parser);
	parser.process(app);
	aboutData.processCommandLine(&parser);

	// create a window
	MainWindow* window=new MainWindow();
	window->show();

	return app.exec();
}
