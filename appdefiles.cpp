#include "appdefiles.h"

namespace AppDefines {

    // Excel
    const AppInfo EXCEL{
        "Excel",
#ifdef Q_OS_WIN
        "C:\\Program Files\\Microsoft Office\\root\\Office16\\EXCEL.EXE",
        "C:\\Program Files\\Microsoft Office\\root\\Office16\\EXCEL.EXE",
#elif Q_OS_MAC
        "/Applications/Microsoft Excel.app",
        "open -a 'Microsoft Excel'"
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

    // VS Code
    const AppInfo VSCODE{
        "VS Code",
#ifdef Q_OS_WIN
        qEnvironmentVariable("LOCALAPPDATA") + "\\Programs\\Microsoft VS Code\\Code.exe",
        qEnvironmentVariable("LOCALAPPDATA") + "\\Programs\\Microsoft VS Code\\Code.exe",
#elif Q_OS_MAC
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
        VSCODE
    };
}
