int deactivate_page()
{
	int decision;
	int newIndex = 0;
	cout << endl;
	accept("\t Do you really want to deactivate your account?\n\t     1. YES\n\t     2. NO\n\tEnter option number(1-2)", &decision, 1, 2);
	if (decision == 1)
	{
		for (int i = 0; i < customer_counter; i++)
		{
			if (i != user)
			{
				customer[newIndex] = customer[i];
				++newIndex;
			}
		}
		customer[customer_counter - 1] = {};
		cout << "You successfully deactivated your account. << endl;
		cout << "Enter any key to proceed to main menu: ";
		cin >> option;
		return 1;
	}
	cout << "Operation cancelled returning to Home";
	return 0;
}
