#include "AForm.hpp"

AForm::AForm() : _name("Default"), _signature(false), _minGradeToSign(150), _minGradeToExecute(150) {
	std::cout << "A generic form is created" << std::endl;
};

AForm::AForm(std::string paramName, int gradeToSign, int gradeToExecute)
	: _name(paramName), _minGradeToSign(gradeToSign), _minGradeToExecute(gradeToExecute) {
	this->_signature = false;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	else
	{
		std::cout << "A form " << _name << " created. ";
		std::cout << "Minimum grade to sign: " <<  _minGradeToSign << ". Minimum grade to execute: " << _minGradeToExecute << std::endl;
	}
};

AForm::~AForm() {
	std::cout << "Form " << _name << " has been destroyed" << std::endl;
};

AForm::AForm(const AForm& copy) : _name(copy._name), _signature(copy._signature), _minGradeToSign(copy._minGradeToSign), _minGradeToExecute(copy._minGradeToExecute)
{
	std::cout << "Form " << _name << " has been copied";
};

AForm& AForm::operator=(const AForm& copy) {
	if (this != &copy)
	{
		this->_signature = copy._signature;
	}
	std::cout << "Copy assignment operator called. It does not copy all attributes!" << std::endl;
	return *this;
};

const std::string& AForm::getName() const {
	return this->_name;
};

const bool& AForm::getSignature() const {
	return this->_signature;
};

const int& AForm::getMinGradeToSign() const {
	return this->_minGradeToSign;
};

const int& AForm::getMinGradeToExecute() const {
	return this->_minGradeToExecute;
};

void	AForm::beSigned(Bureaucrat& signer) {
	if (this->_signature == true)
		throw AForm::FormAlreadySigned();
	else if (signer.getGrade() > this->getMinGradeToSign())
		throw AForm::GradeTooLowException();
	else
		this->_signature = true;
};

void AForm::execute(const Bureaucrat& executor) const {
	if (this->_signature == false)
	{
		std::cout << "Bureaucrat " << executor.getName() << " cannot execute the form " << this->getName() << " as it's not signed yet" << std::endl;
		throw AForm::FormNotSigned();
	}
	if (this->getMinGradeToExecute() < executor.getGrade())
	{
		std::cout << "Bureaucrat " << executor.getName() << ", grade: " << executor.getGrade() << ", cannot execute the form " << this->getName() << " as it requires the grade of " << this->getMinGradeToExecute() << std::endl;
		throw AForm::GradeTooLowException();
	}
	else
		this->beExecuted();
};

const char* AForm::GradeTooHighException::what() const noexcept {
	return ("The grade is too high, please use a lower grade");
};

const char* AForm::GradeTooLowException::what() const noexcept {
	return ("The grade is too low, please use a higher grade");
};

const char* AForm::FormAlreadySigned::what() const noexcept {
	return ("The form has already been signed");
};

const char* AForm::FormNotSigned::what() const noexcept {
	return ("The form has not been signed, unable to execute");
};

std::ostream& operator<<(std::ostream& ostream, AForm& form) {
	ostream << "The form " << form.getName() << ", min grade required to sign: " << form.getMinGradeToSign() << ", min grade required to execute: " << form.getMinGradeToExecute() << ", is signed: " << form.getSignature();
	return (ostream);
};