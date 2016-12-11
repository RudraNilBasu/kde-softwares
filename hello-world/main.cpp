#include<cstdlib>

#include<QApplication>
#include<QCommandLineParser>
#include<KAboutData>
#include<KLocalizedString>
#include<KMessageBox>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	KLocalizedString::setApplicationDomain("tutorial1");

	KAboutData aboutData(
			QStringLiteral("tutorial1"),
			i18n("Tutorial1"),
			QStringLiteral("1.0"),
			i18n("Display a KMessage popup"),
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

	// creating the yes button
	KGuiItem yesButton(
			i18n("Hello"), QString(),
			i18n("This is a tooltip"),
			i18n("Do you want to say Hello ?")
			);

	// creating the no button
	KGuiItem noButton(
			i18n("Goodbye"), QString(),
			i18n("What ?"),
			i18n("Do you want to say Good bye ?")
		 	);

	// creating the popup dialog box and returning the value of button pressed
	return 
		KMessageBox::questionYesNo (0, i18n("Hello World"), i18n("Hello"), yesButton, noButton)
		== KMessageBox::Yes ? EXIT_SUCCESS: EXIT_FAILURE;
}
