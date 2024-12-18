#include <bits/stdc++.h>
#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;

using namespace std;

class PaymentCalculator {
private:
    map<int, double> paymentRates;

public:
    // Default constructor with standard rates
    PaymentCalculator() {
        setDefaultRates();
    }

    // Constructor allowing custom payment rates
    PaymentCalculator(const map<int, double>& customRates) {
        setCustomRates(customRates);
    }

    // Set default payment rates
    void setDefaultRates() {
        // payments can varry for different pages
        paymentRates = {
            {0, 0.0},     // 0 pages
            {1, 30.0},    // 1-2 pages
            {2, 30.0},    // 2-3 pages
            {3, 60.0},    // 3-4 pages
            {4, 60.0}     // 4-5 pages
        };
    }

    // Allow setting custom payment rates
    void setCustomRates(const map<int, double>& customRates) {
        paymentRates = customRates;
    }

    // Calculate payment based on number of pages
    double calculatePayment(int pages) {
        // Find the highest page threshold that matches or is less than current pages
        double payment = 0.0;
        for (auto it = paymentRates.rbegin(); it != paymentRates.rend(); ++it) {
            if (pages >= it->first) {
                payment = it->second;
                break;
            }
        }
        return payment;
    }
};

class ArticleManager {
private:
    string articleText;
    vector<string> pages;
    vector<string> pageLines;
    vector<string> words;
    int paidPages;
    PaymentCalculator paymentCalculator; // this is a new addition
    string outputDirectory; // this is a new addition

    // Helper function to split a string into words
    vector<string> splitWords(const string &text) {
        istringstream stream(text);
        vector<string> result;
        string word;
        while (stream >> word) {
            result.push_back(word);
        }
        return result;
    }

    // Create output directory if it doesn't exist
    void ensureOutputDirectory() {
        if (outputDirectory.empty()) {
            outputDirectory = "article_outputs";
        }
        fs::create_directories(outputDirectory);
    }

public:
    // Constructors
    ArticleManager(const string &articleText) 
        : articleText(articleText), paidPages(0), outputDirectory("article_outputs") {} // output directory is added

    ArticleManager(const string &articleText, const map<int, double>& customRates) 
        : articleText(articleText), paidPages(0), paymentCalculator(customRates), outputDirectory("article_outputs") {}

    // Set custom output directory
    void setOutputDirectory(const string& directory) {
        outputDirectory = directory;
        ensureOutputDirectory();
    }

    void splitIntoPages() {
        int wordsPerLine = 12;
        int linesPerPage = 20;

        // Split article text into words
        words = splitWords(articleText);
        cout << "Total words: " << words.size() << endl;

        // Create lines from words
        vector<string> lines;
        for (int i = 0; i < words.size(); i += wordsPerLine) {
            auto end = min(static_cast<vector<string>::size_type>(i + wordsPerLine), words.size());
            string line;
            for (int j = i; j < end; ++j) {
                line += words[j] + " ";
            }
            if (!line.empty()) line.pop_back(); // Remove trailing space
            lines.push_back(line);
        }

        // Create pages from lines
        for (int i = 0; i < lines.size(); i += linesPerPage) {
            auto end = min(static_cast<vector<string>::size_type>(i + linesPerPage), lines.size());
            string page;
            for (int j = i; j < end; ++j) {
                page += lines[j] + "\n";
            }
            pages.push_back(page);
        }

        // Calculate paid pages
        paidPages = (words.size() + 239) / 240; // Ceiling division
    }

    double calculatePayment() {
        return paymentCalculator.calculatePayment(paidPages);
    }

    void displayPages() {
    double payment = calculatePayment();
    cout << "Total Pages: " << pages.size() << endl;
    cout << "Paid Pages: " << (paidPages > 0 ? paidPages : 0) << endl;
    cout << "Payment Due: $" << fixed << setprecision(2) << payment << "\n" << endl;

    for (int i = 0; i < pages.size(); ++i) {
        cout << "\nPage " << (i + 1) << ":\n" << pages[i] << "\n"; 
        cout << endl; // Added an extra endl for better readability
    }
}


    // Save article to a text file
    void saveToFile(const string& filename = "") {
        ensureOutputDirectory();

        // Generate filename if not provided
        string outputFile = filename;
        if (outputFile.empty()) {
            auto now = chrono::system_clock::now();
            auto timeT = chrono::system_clock::to_time_t(now);
            stringstream ss;
            ss << outputDirectory << "/article_" 
            << put_time(localtime(&timeT), "%Y%m%d_%H%M%S") 
            << ".txt";
            outputFile = ss.str();
        } else {
            outputFile = outputDirectory + "/" + outputFile;
        }

        ofstream outFile(outputFile);
        if (!outFile) {
            throw runtime_error("Could not open file for writing: " + outputFile);
        }

        // Write article details with better formatting
        outFile << "Total Pages: " << pages.size() << "\n";
        outFile << "Paid Pages: " << (paidPages > 0 ? paidPages : 0) << "\n";
        outFile << "Payment Due: $" << fixed << setprecision(2) << calculatePayment() << "\n\n";

        for (int i = 0; i < pages.size(); ++i) {
            outFile << "Page " << (i + 1) << ":\n" << pages[i] << "\n\n";
        }

        outFile.close();
        cout << "\nArticle saved to: " << outputFile << endl;
    }


        void processArticle() {
            cout << "\nProcessing Article...\n" << endl;
            splitIntoPages();
            displayPages();
        }
    };

int main() {
    // try catch block added for extra check
    try {
        // Example with default payment rates
        string articleText = "This is a sample article text that we will use to demonstrate the functionality of our ArticleManager class. "
                                  "It will show how we can split the text into pages, calculate payment, and save the article to a file. "
                                  "The program supports flexible payment structures and can handle articles of various lengths.";
        
        ArticleManager articleManager(articleText);
        articleManager.processArticle();
        articleManager.saveToFile(); // Saves with auto-generated filename

        // Example with custom payment rates
        map<int, double> customRates = {
            {0, 0.0},     // 0 pages
            {1, 25.0},    // 1-2 pages at different rate
            {2, 25.0},    // 2-3 pages are at same rates
            {3, 50.0},    // 3-4 pages at different rate
            {4, 50.0},    // 4-5 pages are at same rates
            {5, 100.0}    // 5+ pages at different rate
        };

        ArticleManager customArticleManager(articleText, customRates);
        customArticleManager.setOutputDirectory("custom_article_outputs");
        customArticleManager.processArticle();
        customArticleManager.saveToFile("custom_rates_article.txt");
    }
    catch (const exception& err) {
        cerr << "Error: " << err.what() << endl;
        return 1;
    }

    return 0;
}