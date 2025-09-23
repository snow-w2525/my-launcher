#include "appdefines.h"

#ifdef Q_OS_MAC
#include <QStandardPaths>
#endif

namespace AppDefines {

const QString DEACTIVATE_PANEL = "QFrame{background-color: rgb(200, 200, 200); border-radius: 10px}";

    // Excel
    const AppInfo EXCEL{
        "Excel",
#if defined(Q_OS_WIN)
        "C:\\Program Files\\Microsoft Office\\root\\Office16\\EXCEL.EXE",
        "C:\\Program Files\\Microsoft Office\\root\\Office16\\EXCEL.EXE",
#elif defined(Q_OS_MAC)
        "/Applications/Microsoft Excel.app",
        "Microsoft Excel",
#endif
        ":/res/icons/icon_xlsx.svg",
        "QFrame{background-color: rgb(92, 255, 160); border-radius: 10px}",
        QVector<QString>({
            "Standard Excel Workbook [no macros] (*.xlsx)",
            "Macro-enabled Workbook (*.xlsm)",
            "Binary Workbook [optimized for performance] (*.xlsb)",
            "Excel 97–2003 Workbook (*.xls)",
            "Template [no macros] (*.xltx)",
            "Macro-enabled Template (*.xltm)",
            "Excel 97–2003 Template (*.xlt)",
            "Excel 4.0 Workspace (*.xlw)",
            "Excel 4.0 Macro (*.xlm)",
            "Comma-Separated Values (*.csv)",
            "Tab-Delimited Text (*.txt)",
            "Space-Delimited Text (*.prn)",
            "Data Interchange Format (*.dif)",
            "Symbolic Link Format (*.slk)",
            "XML Spreadsheet 2003 (*.xml)",
            "Others (*.*)"
        })
    };

    // Word
    const AppInfo WORD{
        "Word",
#if defined(Q_OS_WIN)
        "C:\\Program Files\\Microsoft Office\\root\\Office16\\WINWORD.EXE",
        "C:\\Program Files\\Microsoft Office\\root\\Office16\\WINWORD.EXE",
#elif defined(Q_OS_MAC)
        "/Applications/Microsoft Word.app",
        "Microsoft Word",
#endif
        ":/res/icons/icon_word.svg",
        "QFrame{background-color: rgb(0, 85, 255); border-radius: 10px}",
        QVector<QString>({
            "Standard Word Document (*.docx)",
            "Macro-enabled Word Document (*.docm)",
            "Word 97–2003 Document (*.doc)",
            "Strict Open XML Document (*.docx)",
            "Template [no macros] (*.dotx)",
            "Macro-enabled Template (*.dotm)",
            "Word 97–2003 Template (*.dot)",
            "Rich Text Format (*.rtf)",
            "Plain Text (*.txt)",
            "Web Page (*.htm; *.html)",
            "Filtered Web Page (*.htm; *.html)",
            "Single File Web Page (*.mht; *.mhtml)",
            "OpenDocument Text (*.odt)",
            "PDF Document (*.pdf)",
            "XPS Document (*.xps)",
            "Word XML Document (*.xml)",
            "Word 2003 XML Document (*.xml)",
            "Microsoft Works Document (*.wps)",
            "Others (*.*)"
        })
    };

    // Power Point
    const AppInfo POWERPOINT{
        "Power Point",
#if defined(Q_OS_WIN)
        "C:\\Program Files\\Microsoft Office\\root\\Office16\\POWERPNT.EXE",
        "C:\\Program Files\\Microsoft Office\\root\\Office16\\POWERPNT.EXE",
#elif defined(Q_OS_MAC)
        "/Applications/Microsoft Word.app",
        "Visual Studio Code",
#endif
        ":/res/icons/icon_powerpoint.svg",
        "QFrame{background-color: rgb(255, 0, 0); border-radius: 10px}",
        QVector<QString>({
            "Standard Presentation (*.pptx)",
            "Macro-enabled Presentation (*.pptm)",
            "PowerPoint 97–2003 Presentation (*.ppt)",
            "Strict Open XML Presentation (*.pptx)",
            "Template [no macros] (*.potx)",
            "Macro-enabled Template (*.potm)",
            "PowerPoint 97–2003 Template (*.pot)",
            "Slide Show (*.ppsx)",
            "Macro-enabled Slide Show (*.ppsm)",
            "PowerPoint 97–2003 Slide Show (*.pps)",
            "Add-In (*.ppam)",
            "PowerPoint 97–2003 Add-In (*.ppa)",
            "Others (*.*)"
        })
    };



    // VS Code
    const AppInfo VSCODE{
        "VS Code",
#if defined(Q_OS_WIN)
        qEnvironmentVariable("LOCALAPPDATA") + "\\Programs\\Microsoft VS Code\\Code.exe",
        qEnvironmentVariable("LOCALAPPDATA") + "\\Programs\\Microsoft VS Code\\Code.exe",
#elif defined(Q_OS_MAC)
        "/Applications/Visual Studio Code.app",
        "Visual Studio Code",
#endif
        ":/res/icons/icon_vscode.svg",
        "QFrame{background-color: rgb(0, 170, 255); border-radius: 10px}",
        QVector<QString>({
            "Plain Text (*.txt)",
            "Markdown Document (*.md)",
            "HTML File (*.html)",
            "CSS Stylesheet (*.css)",
            "JavaScript File (*.js)",
            "TypeScript File (*.ts)",
            "Python Script (*.py)",
            "C Source File (*.c)",
            "C++ Source File (*.cpp)",
            "C Header File (*.h)",
            "Java Source File (*.java)",
            "JSON File (*.json)",
            "YAML File (*.yaml)",
            "TOML File (*.toml)",
            "Shell Script (*.sh)",
            "PowerShell Script (*.ps1)",
            "Batch File (*.bat)",
            "Makefile (*.make)",
            "Dockerfile (*.dockerfile)",
            "Git Configuration (*.gitignore)",
            "VSCode Settings (*.code-workspace)",
            "PHP Script (*.php)",
            "Ruby Script (*.rb)",
            "Go Source File (*.go)",
            "Rust Source File (*.rs)",
            "Swift Source File (*.swift)",
            "Kotlin Source File (*.kt)",
            "R Script (*.r)",
            "LaTeX Document (*.tex)",
            "Vue Component (*.vue)",
            "Svelte Component (*.svelte)",
            "React JSX (*.jsx)",
            "React TSX (*.tsx)",
            "SQL Script (*.sql)",
            "GraphQL Schema (*.graphql)",
            "INI Configuration (*.ini)",
            "Others (*.*)"
        })
    };

    const QVector<AppInfo> ALL {
        EXCEL,
        WORD,
        VSCODE,
        POWERPOINT
    };
}
